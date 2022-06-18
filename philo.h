/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:41:27 by sharrach          #+#    #+#             */
/*   Updated: 2022/06/18 18:50:11 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct  args{
	int     nb_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	long	nb_meals;
}	t_args;

int		ft_satoi(const char *str, long *nb);
void	*free2d(char **arr);

#endif