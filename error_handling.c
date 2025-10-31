/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:31:38 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/31 16:54:24 by vahdekiv         ###   ########.fr       */
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

	i = -1;
	while (++i < count)
		safe_thread(table->philos[i]->thread_id, NULL, NULL, JOIN);
	i = -1
	while (++i < table->num_of_philos)
		safe_mutex(table->forks[i]->fork, DESTROY);
	i = -1
	while (++i < table->num_of_philos)
	{
		if (table->philos[i])
			free(table->philos[i]);
		if (table->forks[i])
			free(table->forks[i]);
	}
}
