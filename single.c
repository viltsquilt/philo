/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:52:24 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/05 13:53:34 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	single(t_philo *philo)
{
	philo_state(philo, THINKING);
	safe_mutex(&philo->first_fork->fork, LOCK);
	philo_state(philo, FORK);
	usleep(1001 * philo->table->time_to_die);
	safe_mutex(&philo->first_fork->fork, UNLOCK);
}
