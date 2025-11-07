/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:06:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/07 14:10:57 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	monitor(t_table *table)
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
					printf("Everyone is full\n");
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

static void	routine_helper(t_philo *philo)
{
	if (philo->id % 2 != 0)
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
}

void	philo_routine(void *data)
{
	t_philo	*philo;
	bool	last;

	philo = (void *)data;
	last = false;
	while (1)
	{
		if (philo->table->ready == 1)
		{
			philo->last_meal_time = get_current_time();
			break ;
		}
	}
	if (philo->table->num_of_philos == 1)
		single(philo);
	if (philo->id == philo->table->num_of_philos)
		last = true;
	if (philo->id % 2 != 0 && last == false)
		usleep(5000);
	while (!philo->table->end)
	{
		routine_helper(philo);
		philo_state(philo, SLEEPING);
	}
}

void	dinner_start(t_table *data)
{
	int	i;

	i = -1;
	data->ready = 0;
	while (++i < data->num_of_philos)
	{
		if (safe_thread(&data->philos[i].thread_id, &data->philos[i], CREATE))
			cleanup(data, i);
	}
	data->ready = 1;
	usleep(5000);
	monitor(data);
	cleanup(data, i);
}
