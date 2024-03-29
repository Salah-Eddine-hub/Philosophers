# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 14:21:09 by sharrach          #+#    #+#              #
#    Updated: 2022/06/27 15:37:21 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

HEADER	=	philo.h

SRCS	=	init_philo.c\
			philo.c\
			utils.c\

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g -pthread

RM		=	rm -f

$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS) 

fclean	: 	clean
				$(RM) $(NAME) $(OBJS) 

re		:	fclean all