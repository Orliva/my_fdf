/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:08:24 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:47:24 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculation_x0(t_param *param, int i, int j)
{
	return (X_START + param->zoom * COEF *
			move_x(i * param->sizes.dot_line[i] + j, param));
}

int	calculation_x1_hor(t_param *param, int i, int j)
{
	return (X_START + param->zoom * COEF *
			move_x(i * param->sizes.dot_line[i] + j + 1, param));
}

int	calculation_x1_vert(t_param *param, int i, int j)
{
	return (X_START + param->zoom * COEF *
			move_x((i + 1) * param->sizes.dot_line[i] + j, param));
}

int	calculation_y0(t_param *param, int i, int j)
{
	return (Y_START + param->zoom * (COEF *
			param->coord[i * param->sizes.dot_line[i] + j].y
			- param->play_z *
			param->coord[i * param->sizes.dot_line[i] + j].z *
			cos(M_PI / 6)));
}

int	calculation_y1_vert(t_param *param, int i, int j)
{
	return (Y_START + param->zoom *
			(COEF * param->coord[(i + 1) *
			param->sizes.dot_line[i] + j].y
			- param->play_z * param->coord[(i + 1) *
			param->sizes.dot_line[i] + j].z *
			cos(M_PI / 6)));
}
