/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:04:11 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/15 14:41:10 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (!(c >= '0' || c <= '9'))
		return (1);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	if ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	ft_atosize_t(char *arg)
{
	size_t	i;
	size_t	start;
	size_t	res;

	i = 0;
	start = 0;
	res = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == 32)
		i++;
	if (arg[i] == '\0')
		error_and_exit("Error\nArgument invalid");
	start = i;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 1)
			error_and_exit("Error\nArgument must be positive");
		i++;
	}
	while (arg[start])
	{
		res = res * 10 + (arg[start] - '0');
		start++;
	}
	return (res);
}
