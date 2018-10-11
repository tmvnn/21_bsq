/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:55:22 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/10 19:07:00 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_atoi(char *str)
{
	int		s;
	int		sign;
	int		rez;

	s = 0;
	while (str[s] == 32 || (str[s] >= 9 && str[s] <= 13))
		s++;
	sign = 0;
	if (str[s] == 43 || str[s] == 45)
	{
		if (str[s] == 45)
			sign++;
		s++;
    }
	rez = 0;
	while (str[s] >= 48 && str[s] <= 57)
	{
		rez *= 10;
		rez += str[s] - 48;
		s++;
	}
	if (sign)
		return (-rez);
	else
		return (rez);
}
