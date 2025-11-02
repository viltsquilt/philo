/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:31:38 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/02 15:13:47 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_and_exit(char	*msg)
{
	size_t	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	exit (EXIT_FAILURE);
}

void	cleanup(t_table *table, int count)
{
	int	i;

	i = 0;
	while (i < count)
		safe_thread(&table->philos[i++].thread_id, NULL, JOIN);
	i = 0;
	while (i < count)
		safe_mutex(&table->forks[i++].fork, DESTROY);
	i = 0;
	while (i < count)
		safe_mutex(&table->philos[i++].meals, DESTROY);
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	printf("Simulation ended\n");
	exit(0);
}
