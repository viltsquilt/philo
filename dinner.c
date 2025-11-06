/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:06:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/06 13:13:34 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void monitor(t_table *table)
{
	while (!table->end)
	{
		table->count = 0;
		table->full_count = 0;
		while (table->count < table->num_of_philos)
		{
			if (table->philos[table->count].full)
			{
				safe_mutex(&table->data_lock, LOCK);
				table->full_count++;
				safe_mutex(&table->data_lock, UNLOCK);
				if (table->full_count == table->num_of_philos)
				{
					safe_mutex(&table->data_lock, LOCK);
					table->end = true;
					safe_mutex(&table->data_lock, UNLOCK);
				}
			}
			if (death(table, table->count))
				return ;
			table->count++;
		}
	}
}

void	philo_state(t_philo *philo, t_philo_code code)
{
	if (code == EATING && !philo->table->end)
		eating(philo);
	else if (code == SLEEPING && !philo->table->end)
		sleeping(philo);
	else if (code == FORK && !philo->table->end)
		take_fork(philo);
	else if (!philo->table->end)
		thinking(philo);
}

void	philo_routine(void *data)
{
	t_philo	*philo;

	philo = (void *)data;
	while (1)
	{
		if (philo->table->ready == 1)
			break;
	}
	if (philo->table->num_of_philos == 1)
		single(philo);
	if (philo->id % 2 != 0)
		usleep(500);
//	philo_state(philo, THINKING);
	while (!philo->table->end)
	{
		if (philo->id  % 2 !=  0)
		{
			safe_mutex(&philo->second_fork->fork, LOCK);
			philo_state(philo, FORK);
			safe_mutex(&philo->first_fork->fork, LOCK);
			philo_state(philo, FORK);
			philo_state(philo, EATING);
			safe_mutex(&philo->second_fork->fork, UNLOCK);
			safe_mutex(&philo->first_fork->fork, UNLOCK);
		}
		else
		{
			safe_mutex(&philo->first_fork->fork, LOCK);
			philo_state(philo, FORK);
			safe_mutex(&philo->second_fork->fork, LOCK);
			philo_state(philo, FORK);
			philo_state(philo, EATING);
			safe_mutex(&philo->first_fork->fork, UNLOCK);
			safe_mutex(&philo->second_fork->fork, UNLOCK);
		}
		if (philo->table->end)
			break ;
		philo_state(philo, SLEEPING);
	}
}

void	dinner_start(t_table *data)
{
	int i;

	i = -1;
	data->ready = 0;
	while (++i < data->num_of_philos)
	{
		if (safe_thread(&data->philos[i].thread_id, &data->philos[i], CREATE))
			cleanup(data, i);
	}
	data->ready = 1;
	monitor(data);
	cleanup(data, i);
}
