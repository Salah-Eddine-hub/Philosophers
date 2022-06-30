/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:35:02 by sharrach          #+#    #+#             */
/*   Updated: 2022/06/30 20:22:50 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static	int	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

long long	find_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(long time)
{
	long	c_time;

	c_time = find_time();
	while (c_time + time > find_time())
		usleep(50);
}

int	ft_exit(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i ++;
	write (1, str, i);
	write (1, "\n", 1);
	exit (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	s;
	long	result;

	result = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result *= s;
	if (i != ft_strlen(str))
		return (0);
	return (result);
}
