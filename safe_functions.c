/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:21:57 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/11/10 13:54:53 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		error_and_exit("Malloc failure\n");
	return (ret);
}

int	safe_mutex(t_mtx *mutex, t_code code)
{
	if (code == LOCK)
		return (pthread_mutex_lock(mutex));
	else if (code == UNLOCK)
		return (pthread_mutex_unlock(mutex));
	else if (code == INIT)
		return (pthread_mutex_init(mutex, NULL));
	else if (code == DESTROY)
		return (pthread_mutex_destroy(mutex));
	else
		error_and_exit("Wrong mutex code used\n");
	return (1);
}

int	safe_thread(pthread_t *thread, void *data, t_code code)
{
	void	*f;

	f = philo_routine;
	if (code == CREATE)
		return (pthread_create(thread, NULL, f, data));
	else if (code == DETACH)
		return (pthread_detach(*thread));
	else if (code == JOIN)
		return (pthread_join(*thread, NULL));
	else
		error_and_exit("Wrong thread code used\n");
	return (1);
}
