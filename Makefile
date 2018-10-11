# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbellona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 18:33:43 by lbellona          #+#    #+#              #
#    Updated: 2018/10/10 23:42:39 by lbellona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = *.c
WWW = -Wall -Wextra -Werror
PROG = bsq

all: compile

compile:
	gcc $(WWW) $(SOURCES) -o $(PROG)

clean:
	rm -f $(PROG)
