/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:07:53 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:59:20 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			move_x(int i, t_param *param)
{
	int angle_rad;

	angle_rad = param->angle * (M_PI / 180);
	return (param->coord[i].x * cos(angle_rad)
			- param->coord[i].y * sin(angle_rad));
}

static	int		paint_color(t_param *param, int color, int i)
{
	int color_1;
	int color_2;

	color_1 = color;
	color_2 = 0x009966;
	if (param->coord[i].color != 0)
		color_1 = param->coord[i].color;
	color_1 += color_2 / color_1 /
		param->sizes.count_line * param->sizes.dot_line[i] - 1;
	return (color_1);
}

static	void	draw_horiz_dot(t_param *param, t_brez *brez)
{
	int i;
	int j;
	int color_1;

	brez->flag = 1;
	color_1 = 0x0099CC;
	i = 0;
	while (i < param->sizes.count_line)
	{
		j = 0;
		while (j < param->sizes.dot_line[i] - 1)
		{
			init_brez(brez, param, i, j);
			draw_line(brez, param,
				(color_1 = paint_color(param,
								color_1, i * param->sizes.dot_line[i] + j)));
			j++;
		}
		i++;
	}
}

static	void	draw_vertic_dot(t_param *param, t_brez *brez)
{
	int i;
	int j;
	int color_1;

	brez->flag = 0;
	color_1 = 0x0099CC;
	j = 0;
	while (j < param->sizes.max_dot)
	{
		i = 0;
		while (i < param->sizes.count_line - 1)
		{
			init_brez(brez, param, i, j);
			draw_line(brez, param,
					(color_1 = paint_color(param,
								color_1, i * param->sizes.dot_line[i] + j)));
			i++;
		}
		j++;
	}
}

void			print_pict(t_param *param)
{
	t_brez *brez;

	brez = (t_brez *)malloc((sizeof(t_brez)) * 1);
	draw_horiz_dot(param, brez);
	draw_vertic_dot(param, brez);
	free(brez);
}
