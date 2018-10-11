/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:16 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/10 23:25:32 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# define BUFFSIZE 10240

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_mp
{
	int			nwidth;
	int			nheight;
	char		emp;
	char		obs;
	char		full;
	int			pos;
	int			size;
}				t_mp;

char			*resize_str(char *str1, char *str2);
char			*read2str(int fd);
int				ft_strlen(char *str);
void			map_error();
void			input();
int				ft_atoi(char *str);
void			init_params(t_mp *params);
void			get_map_params(char *charmap, t_mp *params);
void			main_solve(char *charmap);
int				*create_intmap(char *charmap, t_mp *params);
int				lines_is_ok(char *charmap);
int				wide_is_ok(char *charmap, t_mp *params);
void			solv_map(int *map, t_mp params);
void			ft_putchar(char c);
void			fill_map(int *map, t_mp *params);
int				find_nmin(int *map, int nwidth);
int				map_is_valid(char *str, t_mp *params);
void			print_map(int *map, t_mp *params);
void			print_solv(int *map, t_mp *params);

#endif
