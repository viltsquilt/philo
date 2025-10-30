/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:06:20 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/30 13:02:37 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	forks_init(t_philo *philo, t_fork *forks, int i)
{
	philo->first_fork = &forks[i];
	printf("philo %i first fork id = %i\n", i, philo->first_fork->fork_id);
	philo->second_fork = &forks[(i + 1) % philo->table->num_of_philos];
	printf("philo %i second fork id = %i\n", i, philo->second_fork->fork_id);
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while(++i < table->num_of_philos)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		printf("philo id: %i\n", philo->id);
		philo->philo_pos = i;
		philo->meals_counter = 0;
		philo->full = false;
		philo->table = table;
		forks_init(philo, table->forks, i);
	}
}

void	data_init(t_table *table)
{
	int		i;

	i = -1;
	table->end = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->num_of_philos);
	table->forks = safe_malloc(sizeof(t_fork) * table->num_of_philos);
    while (++i < table->num_of_philos)
	{
		safe_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		printf("fork %i id = %i\n", i, table->forks[i].fork_id);
	}
	philo_init(table);
}
