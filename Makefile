# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 18:02:18 by sharrach          #+#    #+#              #
#    Updated: 2022/06/09 18:57:09 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

HEADER	=	philo.h

SRCS	=	test.c\
			philo.c\

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) -g -pthread $(OBJS) -o $(NAME)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS) 

fclean	: clean
				$(RM) $(NAME) $(OBJS) 

re		:	fclean all

.PHONY	:	all clean fclean re