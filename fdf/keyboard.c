/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:09:20 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:58:25 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	key_part_one(int key, t_param *param)
{
	if (key == ESC)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	if (key == C)
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
	if (key == ONE)
	{
		param->angle = 0;
		deal_key(-1, param);
	}
	if (key == TWO)
	{
		param->angle = 90;
		deal_key(-1, param);
		print_pict(param);
	}
	if (key == Z)
	{
		param->zoom++;
		deal_key(-1, param);
	}
	return (1);
}

static	int	key_part_two(int key, t_param *param)
{
	if (key == X)
	{
		param->zoom--;
		deal_key(-1, param);
	}
	if (key == L)
	{
		param->angle += 60;
		deal_key(-1, param);
	}
	if (key == R)
	{
		param->angle -= 60;
		deal_key(-1, param);
	}
	if (key == U)
	{
		param->play_z += 1;
		deal_key(-1, param);
	}
	return (1);
}

static	int	key_part_three(int key, t_param *param)
{
	int	i;

	if (key == ARROW_LEFT)
	{
		i = 0;
		while (i < 209)
		{
			param->coord[i].x -= 1;
			i++;
		}
		deal_key(-1, param);
	}
	if (key == ARROW_RIGHT)
	{
		i = 0;
		while (i < 209)
		{
			param->coord[i].x += 1;
			i++;
		}
		deal_key(-1, param);
	}
	return (1);
}

static	int	key_part_five(int key, t_param *param)
{
	if (key == D)
	{
		param->play_z -= 1;
		deal_key(-1, param);
	}
	return (1);
}

int			deal_key(int key, t_param *param)
{
	printf("Key = %d\n", key);
	if (key == -1)
	{
		deal_key(8, param);
		print_pict(param);
	}
	key_part_one(key, param);
	key_part_two(key, param);
	key_part_three(key, param);
	key_part_four(key, param);
	key_part_five(key, param);
	return (1);
}
