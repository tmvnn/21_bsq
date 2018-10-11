/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:00:58 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/10 23:19:27 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		find_nmin(int *map, int nwidth)
{
	int min;

	min = *(map - 1);
	if (*(map - nwidth) < min)
		min = *(map - nwidth);
	if (*(map - nwidth - 1) < min)
		min = *(map - nwidth - 1);
	return (min);
}

void	print_solv(int *map, t_mp *params)
{
	int		x;
	int		y;
	int		miny;
	int		maxy;
	int		minx;

	minx = params->pos % params->nwidth - params->size + 1;
	miny = params->pos / params->nwidth - params->size + 1;
	maxy = params->pos / params->nwidth;
	y = -1;
	while (++y < params->nheight)
	{
		x = -1;
		while (++x < params->nwidth)
		{
			if (*(map + y * params->nwidth + x) == 0)
				ft_putchar(params->obs);
			else if ((x >= minx && x <= params->pos % params->nwidth) &&
					(y >= miny && y <= maxy))
				ft_putchar(params->full);
			else
				ft_putchar(params->emp);
		}
		ft_putchar('\n');
	}
}

void	fill_map(int *map, t_mp *params)
{
	int		y;
	int		x;
	int		dxy;

	y = -1;
	while (++y < params->nheight)
	{
		x = -1;
		while (++x < params->nwidth)
		{
			dxy = y * params->nwidth + x;
			if (*(map + dxy))
			{
				if (y == 0 || x == 0)
					*(map + dxy) = 1;
				else
					*(map + dxy) = find_nmin(map + dxy, params->nwidth) + 1;
				if (params->size < *(map + dxy))
				{
					params->size = *(map + dxy);
					params->pos = dxy;
				}
			}
		}
	}
}
