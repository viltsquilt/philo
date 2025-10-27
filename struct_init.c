/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:38:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/27 12:35:59 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialise_struct(char **argv, t_philo *philo)
{
	size_t	i;

	i = -1;
	philo->num_of_philos = ft_atosize_t(argv[1]);
	if (philo->num_of_philos == 0)
		error_and_exit("Error\nArgument must be above zero\n");
	philo->id = safe_malloc(sizeof(int) * philo->num_of_philos);
	while (++i < philo->num_of_philos)
		philo->id[i] = i + 1;
	philo->time_to_die = ft_atosize_t(argv[2]);
	if (philo->time_to_die == 0)
		error_and_exit("Error\nArgument must be above zero\n");
	philo->time_to_eat = ft_atosize_t(argv[3]);
	if (philo->time_to_eat == 0)
		error_and_exit("Error\nArgument must be above zero\n");
	philo->time_to_sleep = ft_atosize_t(argv[4]);
	if (philo->time_to_sleep == 0)
		error_and_exit("Error\nArgument must be above zero\n");
	if (argv[5])
		philo->num_times_to_eat = ft_atosize_t(argv[5]);
}
