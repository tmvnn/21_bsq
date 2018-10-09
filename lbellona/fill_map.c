/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:00:58 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/09 20:28:55 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		find_nmin(int *map, int nWidth) //поиск минимума соседей
{
	int min;

	min = *(map - 1);
	if (*(map - nWidth) < min)
		min = *(map - nWidth);
	if (*(map - nWidth - 1) < min)
		min = *(map - nWidth - 1);
	return (min);
}

void	print_map(int *map, t_mp *params)
{
	int		x;
	int		y;

	y = -1;
	while (++y < params->nHeight)
	{
		x = -1;
		while (++x < params->nWidth)
			printf("%d", *(map + y * params->nWidth + x));
		printf("%s \n", "");
	}
}

void	print_solv(int *map, t_mp *params)//int nWidth, int nHeight, int pos, int size)
{
	int		x;
	int		y;
	int		miny;
	int		maxy;
	int		minx;
	int 	maxx;

	minx = params->pos % params->nWidth - params->size + 1;
	miny = params->pos / params->nWidth - params->size + 1;
	maxx = params->pos % params->nWidth;
	maxy = params->pos / params->nWidth;
	y = -1;
	while (++y < params->nHeight)
	{
		x = -1;
		while (++x < params->nWidth)
		{
			if (*(map + y * params->nWidth + x) == 0)
				ft_putchar(params->obs);
			else if ((x >= minx && x <= maxx) && (y >= miny && y <= maxy))
				ft_putchar(params->full);
			else 
				ft_putchar(params->emp);
		}
		ft_putchar('\n');
	}
}

void	fill_map(int *map, t_mp *params)//int nWidth, int nHeight, int *pos)
{
	int		y;
	int		x;
	int		dxy; //сдвиг массива

	y = -1;
	while (++y < params->nHeight)
	{
		x = -1;
		while (++x < params->nWidth)
		{
			dxy = y * params->nWidth + x; //возможно заменить на указатель
			if (*(map + dxy))
			{
				if (y == 0 || x == 0 )
					*(map + dxy) = 1;
				else
					*(map + dxy) = find_nmin(map + dxy, params->nWidth) + 1;
				if (params->size < *(map + dxy)) //запоминаем максимум и его координаты
				{
					params->size = *(map + dxy);
					params->pos = dxy;
				}
			}
		}
	}
}
