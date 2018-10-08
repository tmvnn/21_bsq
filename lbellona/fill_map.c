/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:00:58 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/08 20:07:07 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		find_nmin(int *map, int nWidth)
{
	int min;

	if (!*(map - nWidth - 1))
		return (-1);

	min = *(map - 1);
	if (*(map - nWidth) < min)
		min = *(map - nWidth);
	if (*(map - nWidth - 1) < min)
		min = *(map - nWidth - 1);
	return (min);
}

/*
void	fill_map(int *map, int nWidth, int nHeight)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	nWidth++;
	nHeight++;
	ft_putchar(map[0]);

	while (++y < nHeight)
	{
		while (++x < nWidth)
		{
			if (y == 0 || x == 0 )
				*(map + y * nWidth + x) = 1;
			else
			{
				*(map + y * nWidth + x) = find_nmin();
			}
		}
	}
}*/
