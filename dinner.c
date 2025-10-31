/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:06:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/31 16:57:41 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void monitor(t_table *table)
{
	int	philo_count;
	int	full_count;

	while (!table->end)
	{
		philo_count = 0;
		full_count = -1;
		while (++philo_count != table->num_of_philos)
		{
			if (table->philos[philo_count]->full = true)
			{
				full_count++;
				if (full_count == table->num_of_philos)
				{
					table->end = true;
					break ;
				}
			}
			if ((get_current_time() - table->philos[philo_count]->last_meal_time)
				> table->time_to_die)
			{
				printf("%ld %i has died\n", (get_current_time() - table->start),
				table->philo[philo_count]->philo_id);
				table->end = true;
				break ;
			}
		}
	}
}

static void	print_state(t_philo *philo, t_philo_code code)
{
	if (code == EATING)
		eating(philo);
	else if (code == SLEEPING)
		sleeping(philo);
	else if (code == FORK)
		printf("%ld %i has taken a fork\n", (get_current_time() - table->start),
		table->philo->philo_id);
	else
		printf("%ld %i is thinking\n", (get_current_time() - table->start),
		table->philo->philo_id);
}

static void	philo_routine(void *data);
{
	t_philo	*philo;
	int		count;

	philo = (void *)data;
	while (1);
	{
		if (data->ready == 1)
			break;
	}
	philo->table->start = get_current_time();
	safe_mutex(philo->first_fork->fork, LOCK);
	safe_mutex(philo->second_fork->fork, LOCK);
	print_state(philo, FORK);
	print_state(philo, FORK);
	print_state(philo, EATING);
	safe_mutex(philo->first_fork->fork, UNLOCK);
	safe_mutex(philo->second_fork->fork, UNLOCK);
	print_state(philo, SLEEPING);
	print_state(philo, THINKING);
}

void	dinner_start(t_table *data)
{
	t_philo	*philo;
	int i;

	i = -1;
	data->ready = 0;
	philo = (void *)data;
	while (++i < data->num_of_philos)
	{
		if (safe_thread(philo[i]->thread_id, &philo_routine,
			philo[i], CREATE))
			cleanup(data, i);
	}
	data->ready = 1;
	monitor(data);
	cleanup(data, i);
}
