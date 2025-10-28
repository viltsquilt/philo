/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:38:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/28 13:03:02 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1e3 = 1000

void	parse_input(char **argv, t_table **table)
{
	size_t	i;

	i = -1;
	table->num_of_philos = ft_atol(argv[1]);
	table->philos = safe_malloc(sizeof(t_philo) * table->num_of_philos);
	while (++i < table->num_of_philos)
		table->philos[i]->id = i + 1;
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 6e4 || table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		error_and_exit("Error\nTimestamps must be over 60 ms");
	if (argv[5])
		table->num_times_to_eat = ft_atol(argv[5]);
	else
		table->num_times_to_eat = -1;
}
