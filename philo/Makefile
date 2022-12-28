# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 19:23:17 by fleduc            #+#    #+#              #
#    Updated: 2022/12/13 21:10:25 by fleduc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=thread
RM			= rm -rf

NAME		= philo
SRCS		= src/do_action.c src/checker.c src/cleaner.c src/init.c src/main.c \
			  src/setter.c src/routine.c src/sleep.c src/utils.c src/status_check.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) 
	@$(CC) $(CFLAGS) -o $@ $^ -pthread

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
