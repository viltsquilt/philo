/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:58:02 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/29 14:03:06 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		write(1, "Error\nInvalid number of arguments", 33);
		return (1);
	}
	memset(&table, 0, sizeof(table));
	parse_input(argv, &table);
	printf("num of philos: %ld\n", table.num_of_philos);
	data_init(&table);
//	dinner(&table);
//	cleanup(&table);
//	printf("Philos: %zu\n", philo.num_of_philos);
//	printf("Time to die: %zu\n", philo.time_to_die);
//	printf("Time to eat: %zu\n", philo.time_to_eat);
//	printf("Time to sleep: %zu\n", philo.time_to_sleep);
//	printf("Number of times to eat: %zu\n", philo.num_times_to_eat);
	return (0);
}
/*
void	dinner(t_table **table)
{
	//must hold two forks
	//to avoid fork duplication, mutex forks
	//must sleep after eating
}

int	monitoring(t_table **table)
{

}

//function to monitor philosophers
//loop for checking which philosopher ate last
//function to assess priority i.e. which philosopher has waited longest
//ft_usleep function
//eating function
*/
