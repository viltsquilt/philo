/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:06:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/01 15:48:29 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void monitor(t_table *table)
{
	int	count;
	int	full_count;

//	while (get_current_time() <= table->start)
//		ft_usleep(500);
	while (!table->end)
	{
		count = 0;
		full_count = 0;
		while (count <= table->num_of_philos)
		{
			if (table->philos[count].full)
			{
				full_count++;
				if (full_count == table->num_of_philos)
					table->end = true;
			}
			if ((get_current_time() - table->start - table->philos[count].last_meal_time)
				> table->time_to_die)
			{
				safe_mutex(&table->philos->meals, LOCK);
				print_state("has died\n", (get_current_time() - table->start),
				table->philos[count].id);
				print_state("last meal time\n", table->philos[count].last_meal_time, table->philos[count].id);
				table->end = true;
				safe_mutex(&table->philos->meals, UNLOCK);
				break ;
			}
			count++;
		}
	}
}

void	print_state(char *msg, long value, int id)
{
	long	ms;

	ms = value * 1e2;
	printf("%ldms ", ms);
	printf("%i ", id);
	printf("%s", msg);

}

static void	philo_state(t_philo *philo, t_philo_code code)
{
	if (code == EATING && !philo->table->end)
		eating(philo);
	else if (code == SLEEPING && !philo->table->end)
		sleeping(philo);
	else if (code == FORK && !philo->table->end)
	{
		safe_mutex(&philo->meals, LOCK);
		print_state("has taken a fork\n", (get_current_time() - philo->table->start),
		philo->id);
		safe_mutex(&philo->meals, UNLOCK);
	}
	else if (!philo->table->end)
	{
		safe_mutex(&philo->meals, LOCK);
		print_state("is thinking\n", (get_current_time() - philo->table->start),
		philo->id);
		safe_mutex(&philo->meals, UNLOCK);
	}
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
//	while (get_current_time() <= philo->table->start)
//		ft_usleep(500);
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
