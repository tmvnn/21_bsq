# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 20:29:45 by ggrimes           #+#    #+#              #
#    Updated: 2018/10/08 20:33:24 by ggrimes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FLAGS=-Wall -Wextra -Werror
H=-Iincludes/
NAME=bsq

all: prog

prog:	
		gcc $(FLAGS) $(H) -o $(NAME) main.c srcs/*.c

clean:	
		rm -f $(NAME)
