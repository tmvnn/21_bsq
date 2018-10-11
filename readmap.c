/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:06:00 by lbellona          #+#    #+#             */
/*   Updated: 2018/10/10 23:46:59 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	map_error(void)
{
	write(2, "map error\n", 10);
}

char	*resize_str(char *str1, char *str2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = (char *)malloc(sizeof(char) *
			(ft_strlen(str1) + ft_strlen(str2) + 1));
	i = 0;
	j = 0;
	while (str1[i])
		newstr[j++] = str1[i++];
	free(str1);
	i = 0;
	while (str2[i])
		newstr[j++] = str2[i++];
	newstr[j] = '\0';
	return (newstr);
}

char	*read2str(int fd)
{
	char	*buff;
	char	*ret;
	int		size;

	buff = (char *)malloc(sizeof(char) * (BUFFSIZE + 1));
	ret = (char *)malloc(sizeof(char));
	*ret = '\0';
	while ((size = read(fd, buff, BUFFSIZE)))
	{
		buff[size] = '\0';
		ret = resize_str(ret, buff);
	}
	close(fd);
	free(buff);
	return (ret);
}

void	input(void)
{
	char *inpstr;

	if ((inpstr = read2str(0)) && *inpstr)
		main_solve(inpstr);
	else
		map_error();
	free(inpstr);
}
