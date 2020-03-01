/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:17:30 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:47:33 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_grad(int c1, int c2)
{
	return (c2 / c1);
}

int		calculation_y1_hor(t_param *param, int i, int j)
{
	return (Y_START + param->zoom * (COEF * param->coord[i *
			param->sizes.dot_line[i] + j + 1].y
			- param->play_z * param->coord[i *
			param->sizes.dot_line[i] + j + 1].z *
			cos(M_PI / 6)));
}
