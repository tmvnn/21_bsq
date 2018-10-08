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

void            ft_putchar(char c);
void			fill_map(int *map, int nWidth, int nHeight);
int				find_nmin(int *map, int nWidth);

#endif
