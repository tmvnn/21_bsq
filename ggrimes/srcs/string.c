/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:29:18 by ggrimes           #+#    #+#             */
/*   Updated: 2018/10/08 23:29:21 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int        ft_atoi(char *str)
{
    int    sign;
    int    number;
    
    sign = 0;
    number = 0;
    while (is_separator(*str))
        str++;
    if (*str == '-')
        sign = 1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        number *= 10;
        number += (*str - 48);
        str++;
    }
    if (sign == 1)
        number = -number;
    return (number);
}

int str_len(char *str)
{
    int cnt;
    
    cnt = 0;
    while (str[cnt] != '\0')
        cnt++;
    return (cnt);
}
