/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:22:02 by ggrimes           #+#    #+#             */
/*   Updated: 2018/10/08 19:22:48 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int ac, char *av[])
{
    int count;
    
    count = 1;
    if (ac > 1)
    {
        while (count < ac)
        {
            if (read_map(av[count]) == 1)
                return (1);
            count++;
        }
    }
    return (0);
}
