/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_and_color_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:39:45 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:48:05 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**read_file(char *argv, char *map_line)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ref;
	char	*tmp;
	char	**tmp2;

	if (!(map_line = ft_strnew(0)))
		ft_print_error();
	if (!(fd = open(argv, O_RDONLY, S_IREAD)))
		ft_print_error();
	while ((ref = read(fd, buf, BUFF_SIZE)))
	{
		buf[ref] = '\0';
		tmp = map_line;
		map_line = ft_strjoin(map_line, buf);
		free(tmp);
	}
	close(fd);
	tmp2 = ft_strsplit(map_line, '\n');
	return (tmp2);
}

int		ft_pow(int pow)
{
	int i;
	int res;

	res = 1;
	i = 0;
	while (i < pow)
	{
		res *= 16;
		i++;
	}
	return (res);
}

int		parse_to_10(char *tmp, int i)
{
	int res;
	int counter;

	counter = 5;
	res = 0;
	while (tmp[i])
	{
		if (tmp[i] > 48 && tmp[i] < 57)
			res += ft_pow(counter) * (tmp[i] - 48);
		else
			res += ft_pow(counter) * (tmp[i] - 55);
		counter--;
		i++;
	}
	return (res);
}

void	color_and_z(char *tmp, t_pix *coord, int count)
{
	int i;
	int color;

	color = 0;
	i = 0;
	coord[count].z = ft_atoi(tmp);
	coord[count].color = color;
	while (tmp[i])
	{
		if (tmp[i] == ',')
		{
			i += 3;
			coord[count].color = parse_to_10(tmp, i);
			break ;
		}
		i++;
	}
}
