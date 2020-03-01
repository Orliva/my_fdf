/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:08:45 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:56:00 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	sizes_input(char **map, t_sizes *sizes)
{
	int i;
	int j;
	int count;

	sizes->max_dot = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		count = 0;
		while (map[i][j])
		{
			while (map[i][j] != ' ' && map[i][j])
				j++;
			count++;
			while (map[i][j] == ' ' && map[i][j])
				j++;
		}
		if (count > sizes->max_dot)
			sizes->max_dot = count;
		sizes->dot_line[i] = count;
		i++;
	}
	sizes->count_line = i;
}

static	void	coord_init(char **map, t_pix *coord)
{
	int		i;
	int		j;
	int		count;
	char	**tmp;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		tmp = ft_strsplit(map[i], ' ');
		while (tmp[j])
		{
			coord[count].x = j;
			coord[count].y = i;
			color_and_z(tmp[j], coord, count);
			j++;
			count++;
		}
		ft_strdel(tmp);
		i++;
	}
}

static	t_pix	*struct_coord_init(char **map, t_pix *coord, t_sizes *sizes)
{
	int	i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			while (map[i][j] != ' ' && map[i][j])
				j++;
			count++;
			while (map[i][j] == ' ')
				j++;
		}
		i++;
	}
	if (!(sizes->dot_line = (int *)malloc((sizeof(int)) * i)))
		ft_print_error();
	sizes_input(map, sizes);
	if (!(coord = (t_pix *)malloc(sizeof(t_pix) * count)))
		ft_print_error();
	return (coord);
}

t_pix			*share_map(char **map, t_pix *coord, t_sizes *sizes)
{
	coord = struct_coord_init(map, coord, sizes);
	coord_init(map, coord);
	return (coord);
}
