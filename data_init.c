/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:06:20 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/01 14:32:38 by vahdekiv         ###   ########.fr       */
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
		if (safe_mutex(&philo->meals, INIT))
			cleanup(table, i);
		forks_init(philo, table->forks, i);
		philo->last_meal_time = table->start;
		printf("current time - last meal time: %ld\n", get_current_time() - philo->last_meal_time);
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
	philo_init(table);
}
