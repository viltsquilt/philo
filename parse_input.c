/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:38:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/29 14:07:56 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1e3 = 1000

void	parse_input(char **argv, t_table *table)
{
	table->num_of_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 6e4 || table->time_to_eat < 6e4
		|| (table->time_to_sleep < 6e4))
		error_and_exit("Error\nTimestamps must be over 60 ms");
	if (argv[5])
		table->num_times_to_eat = ft_atol(argv[5]);
	else
		table->num_times_to_eat = -1;
	printf("philos: %ld\n", table->num_of_philos);
	printf("time to die: %ld\n", table->time_to_die);
	printf("time to eat: %ld\n", table->time_to_eat);
	printf("time to sleep: %ld\n", table->time_to_sleep);
	printf("num times to eat: %ld\n", table->num_times_to_eat);
}
