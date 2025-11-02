/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:42:19 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/02 15:27:53 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	print_state(philo, "is eating\n", (get_current_time() - philo->table->start),
	philo->id);
	ft_usleep(philo->table->time_to_eat);
	philo->meals_counter++;
	philo->last_meal_time = get_current_time() - philo->table->start;
	if (philo->meals_counter == philo->table->num_times_to_eat)
		philo->full = true;
}

void	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping\n", (get_current_time() - philo->table->start),
	philo->id);
	ft_usleep(philo->table->time_to_sleep);
}

void	take_fork(t_philo *philo)
{
	print_state(philo, "has taken a fork\n", (get_current_time() - philo->table->start),
	philo->id);
}

void	thinking(t_philo *philo)
{
	print_state(philo, "is thinking\n", (get_current_time() - philo->table->start),
	philo->id);
}

void	death(t_table *table)
{
	printf("%03ldms %i has died\n", (get_current_time() - table->start), table->philos[table->count].id);
//	print_state(&table->philos[table->count], "has died\n", (get_current_time() - table->start),
//	table->philos[table->count].id);
	table->end = true;
}

