/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenzem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:52:04 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:47:49 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			init_brez(t_brez *line, t_param *param, int i, int j)
{
	line->x0 = calculation_x0(param, i, j);
	line->y0 = calculation_y0(param, i, j);
	if (line->flag == 1)
	{
		line->x1 = calculation_x1_hor(param, i, j);
		line->y1 = calculation_y1_hor(param, i, j);
	}
	else
	{
		line->x1 = calculation_x1_vert(param, i, j);
		line->y1 = calculation_y1_vert(param, i, j);
	}
	line->delta_x = line->x0 - line->x1;
	line->delta_y = line->y1 - line->y0;
	line->sign = abs(line->delta_y) > abs(line->delta_x) ? 1 : -1;
	line->sign_x = line->delta_x > 0 ? 1 : -1;
	line->sign_y = line->delta_y > 0 ? 1 : -1;
}

static	void	part_1(t_brez *line, t_param *param, int color)
{
	int f;

	f = 0;
	while (line->x0 != line->x1 || line->y0 != line->y1)
	{
		f += line->delta_y * line->sign_y;
		if (f > 0)
		{
			f -= line->delta_x * line->sign_x;
			line->y0 += line->sign_y;
		}
		line->x0 -= line->sign_x;
		mlx_pixel_put(param->mlx_ptr,
				param->win_ptr, line->x0, line->y0, color);
	}
}

static	void	part_2(t_brez *line, t_param *param, int color)
{
	int f;

	f = 0;
	while (line->x0 != line->x1 || line->y0 != line->y1)
	{
		f += line->delta_x * line->sign_x;
		if (f > 0)
		{
			f -= line->delta_y * line->sign_y;
			line->x0 -= line->sign_x;
		}
		line->y0 += line->sign_y;
		mlx_pixel_put(param->mlx_ptr,
				param->win_ptr, line->x0, line->y0, color);
	}
}

void			draw_line(t_brez *line, t_param *param, int color)
{
	if (line->sign == -1)
		part_1(line, param, color);
	else
		part_2(line, param, color);
}
