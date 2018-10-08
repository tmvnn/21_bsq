/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:00:58 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/09 00:18:27 by lbellona         ###   ########.fr       */
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

void	print_map(int *map, int nWidth, int nHeight)
{
	int		x;
	int		y;

	y = -1;
	while (++y < nHeight)
	{
		x = -1;
		while (++x < nWidth)
			printf("%d", *(map + y * nWidth + x));
		printf("%s \n", "");
	}
}

/*void	print_solv(int *map, int nWidth, int nHeight, int pos, int size);
{
	int		x;
	int		y;
	
	y = -1;
	while (++y < nHeight)
	{
		x = -1;
		while (++x < nWidth)
		{
			if ()
			printf("%d", *(map + y * nWidth + x));
		}
		printf("%s \n", "");
	}
}*/

int		fill_map(int *map, int nWidth, int nHeight, int *pos) //оптимизировать доступ к массиву
{
	int		y;
	int		x;
	int		maxv; //макс размер

	maxv = 0; //проверить на ограничение
	
	y = -1;
	while (++y < nHeight)
	{
		x = -1;
		while (++x < nWidth)
		{	
			if (*(map + y * nWidth + x))
			{
				if (y == 0 || x == 0 )
					*(map + y * nWidth + x) = 1;
				else
					*(map + y * nWidth + x) = find_nmin(map + y * nWidth + x, nWidth) + 1;
				if (maxv < *(map + y * nWidth + x)) //запоминаем максимум и его координаты
				{
					maxv = *(map + y * nWidth + x);
					*pos = y * nWidth + x; //Оптимизировать добавив везде
				}
			}
		}
	}
	return (maxv);
}
