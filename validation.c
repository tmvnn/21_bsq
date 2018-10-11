/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:26:37 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/10 23:35:02 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int			lines_is_ok(char *charmap)
{
	int		l;
	int		i;

	i = -1;
	l = 0;
	while (charmap[++i])
		if (charmap[i] == '\n')
			l++;
	return (l - 1);
}

int			wide_is_ok(char *charmap, t_mp *params)
{
	int		i;
	int		w;

	i = 0;
	while (charmap[i] != '\n')
		i++;
	w = 0;
	while (charmap[++i])
	{
		if (charmap[i] != '\n' && (charmap[i] != params->obs &&
					charmap[i] != params->emp))
			return (0);
		if (charmap[i] == '\n')
		{
			if (w == params->nwidth)
				w = -1;
			else
				return (0);
		}
		w++;
	}
	return (1);
}

int			map_is_valid(char *str, t_mp *params)
{
	int		l;

	l = lines_is_ok(str);
	if (l != params->nheight || l < 1)
		return (0);
	if (params->full == '\0' || params->emp == '\0' || params->obs == '\0')
		return (0);
	if (params->nheight == 0 || params->nwidth == 0)
		return (0);
	if (wide_is_ok(str, params) == 0)
		return (0);
	return (1);
}
