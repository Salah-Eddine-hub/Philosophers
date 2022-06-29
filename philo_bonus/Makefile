# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 18:34:51 by sharrach          #+#    #+#              #
#    Updated: 2022/06/29 15:32:12 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

HEADER	=	philo_bonus.h

SRCS	=	philo_bonus.c\
			utils_bonus.c\
			init_philo_bonus.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

all		:	$(NAME)

clean	:
			$(RM) $(OBJS) 

fclean	: 	clean
				$(RM) $(NAME) $(OBJS) 

re		:	fclean all