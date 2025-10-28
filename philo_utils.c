/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:04:11 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/28 12:50:31 by vahdekiv         ###   ########.fr       */
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

static const char	*valid_input(const char *arg)
{
	int			len;
	const char	*num;

	len = 0;
	while ((*arg >= 9 && *arg <= 13) || *arg == 32)
		arg++;
	if (*arg == '\0')
		error_and_exit("Error\nArgument invalid");
	while (*arg == '+')
		arg++;
	if (*arg == '-')
		error_and_exit("Error\nArgument invalid");
	if (ft_isdigit(*arg) == 1)
		error_and_exit("Error\nArgument invalid");
	num = arg;
	while (ft_isdigit(*arg++) == 0)
		len++;
	if (len > 10)
		error_and_exit("Error\nArgument too large");
	return (num);
}

long	ft_atol(const char *arg)
{
	long	res;
	int		i;

	i = 0;
	res = 0;
	arg = valid_input(arg);
	while (ft_isdigit(arg[i]) == 0)
		res = res * 10 + (arg[i++] - '0');
	if (res >= INT_MAX)
		error_and_exit("Error\nArgument too large");
	return (res);
}
