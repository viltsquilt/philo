/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:58:02 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/15 14:39:15 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
	{
		write(1, "Error\nInvalid number of arguments", 33);
		return (1);
	}
	initialise_struct(argv, &philo);
	eating(philo);
	printf("Philos: %zu\n", philo.num_of_philos);
	printf("Time to die: %zu\n", philo.time_to_die);
	printf("Time to eat: %zu\n", philo.time_to_eat);
	printf("Time to sleep: %zu\n", philo.time_to_sleep);
	printf("Number of times to eat: %zu\n", philo.num_times_to_eat);
	return (0);
}

void	eating(t_philo *philo)
{
	//must hold two forks
	//to avoid fork duplication, mutex forks
	//must sleep after eating
}

int	monitoring(t_philo *philo)
{
	philo->starving_philo = get_hungriest(philo);
}

//function to monitor philosophers
	//loop for checking which philosopher ate last
//function to assess priority i.e. which philosopher has waited longest
//ft_usleep function
//eating function

/*

4 or 5 arguments:

- Number of philosophers (upper limit: 200)
- The time it takes a philo to die if it doesnt eat
- The time it takes a philo to eat
- The time it takes a philo to sleep
- Number of times all philos need to eat before terminating program (optional)

Data Races (Race conditions)

- if multiple threads try to access the same data (for ex: variable), could
	produce undefined behaviour
- Solution: Mutex (lock)
- Mutexes basically secure (lock) the process once the first thread reaches it
	allowing the process to be completed before another thread accesses it
- Mutexes need to be initialised and destroyed at the end of the program

Start with parsing:

- Convert arguments to int (or size_t(?))
- Make sure all arguments are above 0, except the number of meals a philo needs 
	to eat (edge case)
- Use structs

Logic:
- Need a monitor, some function that checks on each philosopher and monitors
	situation
- Need priority logic, so that the philo who has not eaten in the longeest time
	is prioritised

Functions :
- usleep
- gettimeofday
- pthread_create
- pthread_detach
- pthread_join
- pthread_mutex_init (initialise the mutex)
- pthread_mutex_destroy (free the mutex)
- pthread_mutex_lock (lock a process)
- pthread_mutex_unlock (unlock a process)
*/
