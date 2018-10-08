/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:23:07 by ggrimes           #+#    #+#             */
/*   Updated: 2018/10/08 19:23:17 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

int    read_map(char *filename);
void    print_error(void);
void    ft_putchar(char c);
void    ft_putstr(char *str);
int     read_params(int fd);
int     ft_atoi(char *str);
int     ft_open(char *filename);
int     ft_read(int fd, char *c);
int     is_separator(char c);
int     str_len(char *str);
void    ft_putnbr(int n);

#endif
