/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:42:19 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/31 15:56:22 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	printf("%i %i is eating\n", (get_current_time() - philo->table->start),
	philo->philo_id);
	ft_usleep(philo->table->time_to_eat);
	safe_mutex(philo->meals, LOCK);
	philo->meals_counter++;
	philo->last_meal_time = get_current_time();
	safe_mutex(philo->meals, UNLOCK);
	if (philo->meals_counter == philo->table->num_times_to_eat)
		philo->full = true;
}

void	sleeping(t_philo *philo)
{
	printf("%i %i is sleeping\n", (get_current_time() - philo->table->start),
	philo->philo_id);
	ft_usleep(philo->table->time_to_sleep);
	safe_mutex(philo->meals, LOCK);
	philo->last_meal_time = get_current_time() - philo->last_meal_time;
	safe_mutex(philo->meals, UNLOCK);
}
