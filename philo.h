/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:21:05 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/15 14:39:43 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int		*id;
	size_t	num_of_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	num_times_to_eat;
}	t_philo;

int		main(int argc, char **argv);
int		ft_usleep(size_t milliseconds);
int		ft_isdigit(char c);
size_t	ft_atosize_t(char *arg);
size_t	get_current_time(void);
void	initialise_struct(char **argv, t_philo *philo);
void	error_and_exit(char *msg);

#endif
