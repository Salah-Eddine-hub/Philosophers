/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codeVault_explaination.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:07:52 by sharrach          #+#    #+#             */
/*   Updated: 2022/06/09 18:31:58 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void*	routine() {
	printf("Test from threads\n");
	return (NULL);
}

int main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return (0);
}