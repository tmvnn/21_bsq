/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:37:05 by ggrimes           #+#    #+#             */
/*   Updated: 2018/10/08 20:37:07 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}

int    is_separator(char c)
{
    if ((c >= 8 && c <= 13) || c == 32)
        return (1);
    return (0);
}

void    ft_putnbr(int n)
{
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n > 9)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + 48);
}

void    print_error(void)
{
    if (errno == EACCES)
        ft_putstr("Access denied");
    if (errno == EEXIST)
        ft_putstr("File exists");
    if (errno == EMFILE)
        ft_putstr("Too many open files");
    if (errno == ENOENT)
        ft_putstr("File or directory do not exist");
    if (errno == EBADF)
        ft_putstr("Invalid file descriptor");
}
