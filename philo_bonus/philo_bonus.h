/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:34:58 by sharrach          #+#    #+#             */
/*   Updated: 2022/07/01 09:00:43 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<pthread.h>
# include<sys/time.h>
# include"semaphore.h"
# include<signal.h>

typedef struct s_philo
{
	int				num_philos;
	int				num_forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_eat;
	int				num_eat_count;
	int				stop;
	int				died;
	int				*pid;
	sem_t			*block_printf;
	sem_t			*block_fork;
	long long		t_start;
	int				index;
	long long		t_meal;
	pthread_t		check_monitor;
}t_philo;

long long	find_time(void);
int			ft_exit(char *str);
int			ft_atoi(const char *str);
void		ft_usleep(long time);
t_philo		*init_philo(int argc, char **argv);

#endif
