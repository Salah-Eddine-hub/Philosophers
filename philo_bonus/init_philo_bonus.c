/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:11:16 by sharrach          #+#    #+#             */
/*   Updated: 2022/06/29 12:22:42 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo	*init_data(int argc, char **argv)
{
	t_philo	*tmp;

	tmp = (t_philo *)malloc(sizeof(t_philo));
	if (!tmp)
        return (0);
	tmp->num_philos = find_argv(argv[1]);
	tmp->num_forks = tmp->num_philos;
	tmp->t_die = find_argv(argv[2]);
	tmp->t_eat = find_argv(argv[3]);
	tmp->t_sleep = find_argv(argv[4]);
	if (tmp->num_philos < 1 || tmp->num_philos > 200 || tmp->t_die == -1 ||
		tmp->t_eat == -1 || tmp->t_sleep == -1)
		return (printf("Error\nWrong arguments\n"), -1);
	tmp->num_eat = -1;
	if (argc == 6)
	{
		tmp->num_eat = find_argv(argv[5]);
		if (tmp->num_eat == -1)
		    return (printf("Error\nWrong arguments\n"), -1);
	}
	tmp->num_eat_count = 0;
	tmp->stop = 0;
	tmp->died = 0;
	return (tmp);
}

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*tmp;

	if (argc < 5 || argc > 6)
		return (printf("Error\nWrong num of argument\n"), -1);
	tmp = init_data(argc, argv);
	tmp->pid = (int *)malloc(sizeof(int) * tmp->num_forks);
	if (!tmp->pid)
        return (0);
	sem_unlink("/block_print");
	sem_unlink("/block_forks");
	tmp->block_printf = sem_open("/block_print", O_CREAT, 0644, 1);
	tmp->block_fork = sem_open("/block_forks", O_CREAT,
								0644, tmp->num_forks);
	if (tmp->block_printf <= 0 || tmp->block_fork <= 0)
		return (printf("Error\n"), -1);
	return (tmp);
}