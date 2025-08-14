/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:38:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/14 15:03:51 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	intialise_struct(char **argv, t_philo *philo)
{
	philo->num_of_philos = ft_atosize_t(argv[1]);
	if (philo->num_of_philos == 0)
		error_and_exit("Error\nArgument must be above zero\n");
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

size_t	ft_atosize_t(char *arg)
{
	size_t	i;
	size_t	start;
	size_t	res;

	i = 0;
	start = 0;
	res = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || argv[i] == 32)
		i++;
	if (arg[i] == '\0')
		error_and_exit("Error\nArgument invalid");
	start = i;
	while (arg[i])
	{
		if (ft_isdigit(arg[i] == 1)
			error_and_exit("Error\nArgument must be positive");
		i++;
	}
	while (arg[start])
	{
		res = res * (arg[start] - '0')
		start++;
	}
	return (start);
}
