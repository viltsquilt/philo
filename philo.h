/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:21:05 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/28 13:08:52 by vahdekiv         ###   ########.fr       */
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
# include <errno.h>
# include <stdbool.h>

typedef struct s_table t_table;

typedef pthread_mutex_t t_mtx;

typedef enum e_opcode
{
	INIT,
	LOCK,
	JOIN,
	DETACH,
	CREATE,
	DESTROY,
	UNLOCK
}	t_opcode;

typedef struct s_fork;
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

struct s_table
{
	long	num_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_times_to_eat;
	long	start;
	bool	end;
	t_philo	*philos;
	t_fork	*forks;
}	t_table;

int		main(int argc, char **argv);
int		ft_usleep(size_t milliseconds);
int		ft_isdigit(char c);
long	ft_atol(char *arg);
size_t	get_current_time(void);
void	parse_input(char **argv, t_philo *philo);
void	error_and_exit(char *msg);

#endif
