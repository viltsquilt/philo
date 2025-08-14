/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:58:02 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/14 15:07:24 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main (int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 || argc != 6)
	{
		write(1, "Error\nInvalid number of arguments", 33);
		return (1);
	}
	initialise_struct(argv, &philo);
}

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

*/
