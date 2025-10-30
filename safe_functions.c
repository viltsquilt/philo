/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:21:57 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/30 16:00:49 by vahdekiv         ###   ########.fr       */
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

static int mutex_wrapper(int status)
{
	return (status);
}

int	safe_mutex(t_mtx *mutex, t_code code)
{
	if (code == LOCK)
		return (mutex_wrapper(pthread_mutex_lock(mutex)));
	else if (code == UNLOCK)
		return (mutex_wrapper(pthread_mutex_unlock(mutex)));
	else if (code == INIT)
		return (mutex_wrapper(pthread_mutex_init(mutex, NULL)));
	else if (code == DESTROY)
		return (mutex_wrapper(pthread_mutex_destroy(mutex)));
	else
		error_and_exit("Wrong mutex code used\n");
	return (1);
}

static int	thread_wrapper(int status)
{
	return (status);
}

int	safe_thread(pthread_t *thread, void *(*f)(void *),
		void *data, t_code code)
{
	if (code == CREATE)
		return (thread_wrapper(pthread_create(thread, NULL, f, data)));
	else if (code == DETACH)
		return (thread_wrapper(pthread_detach(*thread)));
	else if (code == JOIN)
		return (thread_wrapper(pthread_join(*thread, NULL)));
	else
		error_and_exit("Wrong thread code used\n");
	return (1);
}
