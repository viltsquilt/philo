/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:42:19 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/01 15:20:50 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	safe_mutex(&philo->meals, LOCK);
	print_state("is eating\n", (get_current_time() - philo->table->start),
	philo->id);
	ft_usleep(philo->table->time_to_eat);
	philo->meals_counter++;
	philo->last_meal_time = get_current_time() - philo->table->start;
	if (philo->meals_counter == philo->table->num_times_to_eat)
		philo->full = true;
	safe_mutex(&philo->meals, UNLOCK);
}

void	sleeping(t_philo *philo)
{
	safe_mutex(&philo->meals, LOCK);
	print_state("is sleeping\n", (get_current_time() - philo->table->start),
	philo->id);
	ft_usleep(philo->table->time_to_sleep);
	safe_mutex(&philo->meals, UNLOCK);
}
