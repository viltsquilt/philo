/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:57:30 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/10 14:04:46 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_util(t_philo *philo)
{
	bool	last;

	last = false;
	if (philo->id == philo->table->num_of_philos)
		last = true;
	if (philo->id % 2 != 0 && last == false)
		usleep(5000);
	while (!philo->table->end)
	{
		routine_helper(philo);
		philo_state(philo, SLEEPING);
		usleep(100);
	}
}
