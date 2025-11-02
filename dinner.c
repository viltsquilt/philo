/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:06:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/02 15:50:17 by vahdekiv         ###   ########.fr       */
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
				safe_mutex(&table->philos[table->count].meals, LOCK);
				table->full_count++;
				safe_mutex(&table->philos[table->count].meals, UNLOCK);
				if (table->full_count == table->num_of_philos)
				{
					safe_mutex(&table->philos[table->count].meals, LOCK);
					table->end = true;
					safe_mutex(&table->philos[table->count].meals, UNLOCK);
				}
			}
			if ((get_current_time() - table->start -
				table->philos[table->count].last_meal_time) > table->time_to_die)
			{
				safe_mutex(&table->philos[table->count].meals, LOCK);
				death(table);
//				printf("%03ldms %i has died\n", (get_current_time() - table->start), table->philos[table->count].id);
//				table->end = true;
				safe_mutex(&table->philos[table->count].meals, UNLOCK);
				break ;
			}
//			safe_mutex(&table->philos[table->count].meals, LOCK);
			table->count++;
//			safe_mutex(&table->philos[table->count].meals, UNLOCK);
		}

	}
}

void	print_state(t_philo *philo, char *msg, long value, int id)
{
	long	ms;

	ms = value;
	if (!philo->table->end)
	{
		safe_mutex(&philo->meals, LOCK);
		printf("%03ld %i %s", ms, id, msg);
		safe_mutex(&philo->meals, UNLOCK);
	}

}

static void	philo_state(t_philo *philo, t_philo_code code)
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
	philo_state(philo, THINKING);
	while (!philo->table->end)
	{
		safe_mutex(&philo->first_fork->fork, LOCK);
		philo_state(philo, FORK);
		safe_mutex(&philo->second_fork->fork, LOCK);
		philo_state(philo, FORK);
		philo_state(philo, EATING);
		safe_mutex(&philo->first_fork->fork, UNLOCK);
		safe_mutex(&philo->second_fork->fork, UNLOCK);
		philo_state(philo, SLEEPING);
		philo_state(philo, THINKING);
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
