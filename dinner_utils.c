/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:42:19 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/10 13:50:54 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	philo->last_meal_time = get_current_time();
	safe_mutex(&philo->table->data_lock, LOCK);
	if ((!philo->table->end
			&& philo->meals_counter < philo->table->num_times_to_eat
			&& philo->table->num_times_to_eat > 0)
		|| (!philo->table->end
			&& philo->table->num_times_to_eat == -1))
		printf("%ld %i is eating\n", (get_current_time() - philo->table->start),
			philo->id);
	safe_mutex(&philo->table->data_lock, UNLOCK);
	ft_usleep(philo->table->time_to_eat);
	philo->meals_counter++;
	if (philo->meals_counter == philo->table->num_times_to_eat)
		philo->full = true;
}

void	sleeping(t_philo *philo)
{
	safe_mutex(&philo->table->data_lock, LOCK);
	if (!philo->table->end && philo->full == false)
		printf("%ld %i is sleeping\n",
			(get_current_time() - philo->table->start), philo->id);
	safe_mutex(&philo->table->data_lock, UNLOCK);
	ft_usleep(philo->table->time_to_sleep);
	thinking(philo);
}

void	take_fork(t_philo *philo)
{
	safe_mutex(&philo->table->data_lock, LOCK);
	if (!philo->table->end && philo->full == false)
		printf("%ld %i has taken a fork\n",
			(get_current_time() - philo->table->start), philo->id);
	safe_mutex(&philo->table->data_lock, UNLOCK);
}

void	thinking(t_philo *philo)
{
	safe_mutex(&philo->table->data_lock, LOCK);
	if (!philo->table->end && philo->full == false)
	{
		printf("%ld %i is thinking\n",
			(get_current_time() - philo->table->start), philo->id);
	}
	safe_mutex(&philo->table->data_lock, UNLOCK);
	if (philo->table->time_to_eat + philo->table->time_to_sleep
		+ 1000 > philo->table->time_to_die)
		usleep(500);
}

int	death(t_table *table, int i)
{
	safe_mutex(&table->data_lock, LOCK);
	if ((get_current_time()
			- table->philos[i].last_meal_time) > table->time_to_die)
	{
		printf("%ld %i died\n",
			(get_current_time() - table->start), table->philos[i].id);
		table->end = true;
		safe_mutex(&table->data_lock, UNLOCK);
		return (1);
	}
	safe_mutex(&table->data_lock, UNLOCK);
	return (0);
}
