/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:34:25 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/10 23:36:44 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	init_params(t_mp *params)
{
	params->nheight = 0;
	params->nwidth = 0;
	params->pos = 0;
	params->emp = '\0';
	params->obs = '\0';
	params->full = '\0';
	params->size = 0;
}

void	get_map_params(char *charmap, t_mp *params)
{
	int		i;
	int		j;
	char	*toint;
	
	i = 0;
	while (charmap[i] != '\n')
		i++;
	if (i >= 4)
	{
		params->full = charmap[i - 1];
		params->obs = charmap[i - 2];
		params->emp = charmap[i - 3];
		toint = (char *)malloc(sizeof(char) * (i - 3  + 1));
		toint[i - 3 + 1] = '\0';
		j = -1;
		while (++j < i - 3)
			toint[j] = charmap[j];
		params->nheight = ft_atoi(toint);
		free(toint);
	}
	while (charmap[++i] != '\n')
		params->nwidth += 1;
}

int		*create_intmap(char *charmap, t_mp *params)
{
	int		*intmap;
	int		i;
	int		j;

	i = 0;
	intmap = 0;
	while (charmap[i] != '\n')
		i++;
	intmap = (int *)malloc(sizeof(int) * (params->nheight * params->nwidth));
	j = 0;
	while (charmap[++i])
	{
		if (charmap[i] != '\n')
		{
			if (charmap[i] == params->emp)
				intmap[j++] = -1;
			else
				intmap[j++] = 0;
		}
	}
	return (intmap);
}

void	main_solve(char *charmap)
{
	t_mp	params;
	int		*map;
	
	init_params(&params);
	get_map_params(charmap, &params);
	if (map_is_valid(charmap, &params))
	{
		map = create_intmap(charmap, &params);
		solv_map(map, params);
	}
	else
		map_error();
}

int		main(int argc, char **argv)
{          
	int		i;
	int		fd;
	char	*charmap;

	if (argc <= 1)
		input();
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
				map_error();
				if (i >= 1 && i < argc - 1)
					write(2, "\n", 1);
				continue;
			}
			if ((charmap = read2str(fd)))
				main_solve(charmap);
			else
				map_error();
			free(charmap);
			if (i >= 1 && i < argc - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
