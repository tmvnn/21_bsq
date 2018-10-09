/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:16 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/08 20:07:44 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //DELETE!!!

typedef    struct    s_mp
{
    int         nWidth;
    int         nHeight;
    char        emp;
    char        obs;
    char        full;
    int         pos;
    int         size;
}                t_mp;

void            ft_putchar(char c);
void			fill_map(int *map, t_mp *params);// int nHeight, int *pos);
int				find_nmin(int *map, int nWidth);
void            print_map(int *map, t_mp *params);
void            print_solv(int *map, t_mp *params); //int nWidth, int nHeight, int pos, int size);

#endif
