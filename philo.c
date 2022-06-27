/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:50:04 by sharrach          #+#    #+#             */
/*   Updated: 2022/06/27 18:55:49 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->mutex_printf);
	if (!philo->data->stop)
		printf("%lld %d %s\n",
				find_time() - philo->data->t_start, philo->index, str);
	pthread_mutex_unlock(&philo->data->mutex_printf);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->data->stop)
	{
		philo_print(philo, "is thinking");
		pthread_mutex_lock(philo->lf);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->rf);
		philo_print(philo, "has taken a fork");
		philo_print(philo, "is eating");
		usleep(philo->data->t_eat * 1000 - 20000);
		philo->t_meal = find_time();
		pthread_mutex_unlock(philo->rf);
		pthread_mutex_unlock(philo->lf);
		if (!philo->data->stop)
			philo->num_eat_count += 1;
		philo_print(philo, "is sleeping");
		usleep(philo->data->t_sleep * 1000 - 20000);
	}
	return (0);
}

void	*check_thread(void *args)
{
	t_philo	*philos;
	int		i;
	int		flag_all_eat;

	philos = (t_philo *)args;
	while (!philos->data->stop)
	{
		i = 0;
		flag_all_eat = 0;
		while (i < philos->data->num_philos)
		{
			if (find_time() - (philos + i)->t_meal > philos->data->t_die)
			{
				philo_print(philos + i, "died");
				philos->data->stop = 1;
				break ;
			}
			if (philos->data->num_eat != -1 &&
				(philos + i)->num_eat_count >= philos->data->num_eat)
				flag_all_eat++;
			i++;
		}
		if (flag_all_eat == philos->data->num_philos)
			philos->data->stop = 1;
	}
	return (0);
}

void	philo_start(t_philo *philos)
{
	int	i;

	i = 0;
	philos->data->t_start = find_time();
	while (i < philos->data->num_philos)
	{	
		(philos + i)->t_meal = find_time();
		if (pthread_create(&(philos + i)->pth_t, NULL, &routine, philos + i))
			printf("Error\nFailed to create the thread");
		pthread_detach((philos + i)->pth_t);
		usleep(50);
		i++;
	}
	if (pthread_create(&philos->data->check_thread,
						NULL, &check_thread, philos))
		printf("Error\nFailed to create the thread");
	if (pthread_join(philos->data->check_thread, NULL))
		printf("Error\nFailed to join the thread");
	i = 0;
	while (i < philos->data->num_forks)
	{
		pthread_mutex_destroy(&philos->data->mutex_fork[i]);
		i ++;
	}
	pthread_mutex_destroy(&philos->data->mutex_printf);
}

int	main(int argc, char **argv)
{
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (printf("Error\nWrong number of arguments"));
	if (init_philos(&philos, argc, argv) == -1)
		return (0);
	philo_start(philos);
	return (0);
}
