/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:21:57 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/28 17:30:53 by vahdekiv         ###   ########.fr       */
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

static void mutex_error_wrapper(int status)
{
	if (status == 0)
		return ;
	else
		error_and_exit("Mutex error\n");
}

void	safe_mutex(t_mtx *mutex, t_code code)
{
	if (code == LOCK)
		mutex_wrapper(pthread_mutex_lock(mutex))
	else if (code == UNLOCK)
		mutex_wrapper(pthread_mutex_unlock(mutex))
	else if (code == INIT)
		mutex_wrapper(pthread_mutex_init(mutex, NULL));
	else if (code == DESTROY)
		mutex_wrapper(pthread_mutex_destroy(mutex));
	else
		error_and_exit("Wrong mutex code used\n");
}

static void	thread_error_wrapper(int status)
{
	if (status == 0)
		return ;
	else
		error_and_exit("Thread error\n");
}

void	safe_thread(pthread_t *thread, void *(*f)(void *),
		void *data, t_code code)
{
	if (code == CREATE)
		thread_error_wrapper(pthread_create(thread, NULL, f, data));
	else if (code == DETACH)
		thread_error_wrapper(pthread_detach(thread));
	else if (code == JOIN)
		thread_error_wrapper(pthread_join(thread, NULL));
	else
		error_and_exit("Wrong thread code used\n");
}
