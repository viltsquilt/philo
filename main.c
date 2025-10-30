/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:58:02 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/10/30 15:36:28 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		write(1, "Error\nInvalid number of arguments", 33);
		return (1);
	}
	memset(&table, 0, sizeof(table));
	parse_input(argv, &table);
	data_init(&table);
	dinner_start(&table);
//	cleanup(&table);
	return (0);
}
