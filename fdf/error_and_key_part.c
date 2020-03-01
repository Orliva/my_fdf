/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_key_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:20:06 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:45:14 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_error(void)
{
	printf("Error\n");
	exit(-1);
}

int		key_part_four(int key, t_param *param)
{
	int i;

	if (key == ARROW_DOWN)
	{
		i = 0;
		while (i < 209)
		{
			param->coord[i].y += 1;
			i++;
		}
		deal_key(-1, param);
	}
	if (key == ARROW_TOP)
	{
		i = 0;
		while (i < 209)
		{
			param->coord[i].y -= 1;
			i++;
		}
		deal_key(-1, param);
	}
	return (1);
}
