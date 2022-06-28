/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:14:47 by sharrach          #+#    #+#             */
/*   Updated: 2022/06/28 09:18:26 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_args(t_data **data, int argc, char **argv)
{
	t_data	*tmp;

	tmp = (t_data *)malloc(sizeof(t_data));
	if (!tmp)
		return (0);
	tmp->num_philos = ft_atoi(argv[1]);
	tmp->num_forks = tmp->num_philos;
	tmp->t_die = ft_atoi(argv[2]);
	tmp->t_eat = ft_atoi(argv[3]);
	tmp->t_sleep = ft_atoi(argv[4]);
	if (tmp->num_philos < 1 || tmp->num_philos > 200 || tmp->t_die < 1
		|| tmp->t_eat < 1 || tmp->t_sleep < 1)
		return (printf("Error\nWrong arguments\n"), -1);
	tmp->num_eat = -1;
	if (argc == 6)
	{
		tmp->num_eat = ft_atoi(argv[5]);
		if (tmp->num_eat == -1)
			return (printf("Error\nWrong arguments\n"), -1);
	}
	tmp->stop = 0;
	*data = tmp;
	return (0);
}
 
static int	init_mutex_fork(t_data *data)
{
	int	i;

	data->mutex_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
						* data->num_forks);
	if (!data->mutex_fork)
		return (0);
	i = 0;
	while (i < data->num_forks)
	{
		if (pthread_mutex_init(data->mutex_fork + i, NULL))
			return (printf("Error\n"), -1);
		i++;
	}
	return (0);
}

static void	init_philo(t_philo *philo, int i,
						t_data *data, pthread_mutex_t *forks)
{
	philo->index = i + 1;
	philo->num_eat_count = 0;
	philo->t_meal = 0;
	philo->data = data;
	if (i == 0)
	{
		philo->lf = forks + data->num_philos - 1;
		philo->rf = forks + i;
	}
	else
	{
		philo->lf = forks + i - 1;
		philo->rf = forks + i;
	}
}

int	init_philos(t_philo **philos, int argc, char **argv)
{
	t_data	*data;
	t_philo	*tmp;
	int		i;

	if (get_args(&data, argc, argv) == -1)
		return (-1);
	if (pthread_mutex_init(&data->mutex_printf, NULL))
		return (printf("Error\n"), -1);
	if (init_mutex_fork(data) == -1)
		return (-1);
	tmp = (t_philo *)malloc(sizeof(t_philo) * data->num_philos);
	if (!tmp)
		return (0);
	i = 0;
	while (i < data->num_philos)
	{
		init_philo(tmp + i, i, data, data->mutex_fork);
		i++;
	}
	*philos = tmp;
	return (0);
}
