/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:46:31 by ggrimes           #+#    #+#             */
/*   Updated: 2018/10/08 19:46:33 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int    read_map(char *filename)
{
    int fd;
    char c;
    int cnt_n;
    char str[10];
    char *pstr;
    int str_cnt;
    char empty_ch;
    char obs_ch;
    char full_ch;
    int nums[1000];
    int i;
    int j;
    
    pstr = str;
    if ((fd = ft_open(filename)) == -1)
        return (1);
    cnt_n = 0;
    while (ft_read(fd, &c) > 0)
    {
        if (c >= '0' && c <= '9')
        {
            *pstr = c;
        }
        else
            break ;
    }
    str_cnt = ft_atoi(pstr);
    empty_ch = c;
    if (ft_read(fd, &obs_ch) < 1)
        return (1);
    if (ft_read(fd, &full_ch) < 1)
        return (1);
    if (ft_read(fd, &c) < 1)
        return (1);
    //if (ft_read(fd, &c) < 1)
        //return (1);
    i = 0;
    while (ft_read(fd, &c) > 0)
    {
        if (c == empty_ch)
            nums[i] = 2;
        if (c == obs_ch)
            nums[i] = 0;
        if (c == '\n')
            nums[i] = 9;
        i++;
    }
    j = 0;
    while (j < i)
    {
        if (nums[j] == 9)
            ft_putchar('\n');
        else
            ft_putnbr(nums[j]);
        j++;
    }
    return (0);
}

int ft_open(char *filename)
{
    int fd;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        print_error();
        return (-1);
    }
    return (fd);
}

int ft_read(int fd, char *c)
{
    int b_read;
    
    b_read = read(fd, c, 1);
    if (b_read == -1)
        print_error();
    //if (b_read == 0)
        //ft_putstr("File is empty");
    return (b_read);
}


