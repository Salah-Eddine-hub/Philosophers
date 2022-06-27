/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:49:46 by sharrach          #+#    #+#             */
/*   Updated: 2022/06/27 15:44:24 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				num_philos;
	int				num_forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_eat;
	int				stop;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_printf;
	long long		t_start;
	pthread_t		check_thread;
}t_data;

typedef struct s_philo
{
	int				index;
	int				num_eat_count;
	long long		t_meal;
	t_data			*data;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	pthread_t		pth_t;
}t_philo;

long long	find_time(void);
int			init_philos(t_philo **philos, int argc, char **argv);
int			ft_atoi(const char *str);

#endif
