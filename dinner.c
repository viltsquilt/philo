/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:06:54 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/30 16:35:06 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	print_state(t_table *tabe, t_philo_code code)
{
	if (code == EATING)
		printf("%i %i is eating\n", (get_current_time() - table->start),
		table->philo->philo_id);
	if (code == SLEEPING)
		printf("%i %i is sleeping\n", (get_current_time() - table->start),
		table->philo->philo_id);
	if (code == THINKING)
		printf("%i %i is thinking\n", (get_current_time() - table->start),
		table->philo->philo_id);
	if (code == DEAD)
		printf("%i %i died\n", (get_current_time() - table->start),
		table->philo->philo_id);
}

static void	philo_routine(void *data);
{
	t_philo	*philo;
	int		count;

	philo = (void *)data;
	while (1);
	{
		if (data->ready == 1)
			break;
	}
	philo->table->start = get_current_time();
	//eat
	print_state(philo, EATING);
	//sleep
	print_state(philo, SLEEPING);
	//think
	print_state(philo, THINKING);
	//monitoring()
}

void	dinner_start(t_table *data)
{
	// sync philos
	int i;

	i = -1;
	data->ready = 0;
	data->philos = (void *)data;
	while (++i < data->num_of_philos)
	{
		if (safe_thread(data->philos[i]->thread_id, &philo_routine,
			data->philos, CREATE))
		{
			//cleanup and exit
			//TODO 
		}
	}
	data->ready = 1;
}
