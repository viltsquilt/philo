/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:06:20 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/05 15:57:44 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	forks_init(t_philo *philo, t_fork *forks, int i)
{
	philo->first_fork = &forks[i];
	philo->second_fork = &forks[(i + 1) % philo->table->num_of_philos];
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
		philo->philo_pos = i;
		philo->meals_counter = 0;
		philo->full = false;
		philo->table = table;
		forks_init(philo, table->forks, i);
		philo->last_meal_time = table->start;
//		philo->last_meal_time = 0;
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
		if (safe_mutex(&table->forks[i].fork, INIT))
			cleanup(table, i);
		table->forks[i].fork_id = i;
	}
	if (safe_mutex(&table->data_lock, INIT))
		cleanup(table, table->num_of_philos);
	philo_init(table);
}
