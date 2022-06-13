/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:23:42 by sharrach          #+#    #+#             */
/*   Updated: 2022/06/13 14:42:18 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t tid[2];
int counter;

void*	dothis(void *argv)
{
	unsigned long i;
	
	i = 0;
	counter += 1;
	printf("job %d has started\n", counter);
	for (i = 0; i < (0xFFFFFFFF); i++)
		;
	printf("Job %d has finished\n", counter);
	return (NULL);
}

int main(void)
{
	int i;
	int error;

	i = 0;
	while(i < 2)
	{
		error = pthread_create(&(tid[i]), NULL, &dothis, NULL);
		if (error != 0)
			printf("Tread can't be created : [%s]", strerror(error));
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	return (0);
	
}
