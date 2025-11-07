/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:38:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/07 11:48:53 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(char **argv, t_table *table)
{
	table->num_of_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| (table->time_to_sleep < 60))
		error_and_exit("Error\nTimestamps must be over 60 ms\n");
	if (table->num_of_philos > MAX_PHILOS)
		error_and_exit("Error\nToo many philos\n");
	if (argv[5])
		table->num_times_to_eat = ft_atol(argv[5]);
	else
		table->num_times_to_eat = -1;
	table->start = get_current_time();
}
