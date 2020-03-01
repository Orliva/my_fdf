/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:06:40 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:59:25 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	param_init(t_param *param)
{
	param->mlx_ptr = mlx_init();
	param->win_ptr =
		mlx_new_window(param->mlx_ptr, 2000, 2000, "my_graph_work:)");
	param->map_line = NULL;
	param->coord = NULL;
	param->play_z = 1;
	param->zoom = 1;
	param->angle = 0;
}

void			clear_mem(t_param *param, char **map)
{
	free(param->mlx_ptr);
	free(param->win_ptr);
	free(param->map_line);
	free(param->coord);
	free(param->sizes.dot_line);
	free(param);
	ft_strdel(map);
}

int				main(int argc, char **argv)
{
	char	**map;
	t_param	*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		write(1, "Error", 4);
	if (argc == 2)
	{
		param_init(param);
		map = read_file(argv[1], param->map_line);
		param->coord = share_map(map, param->coord, &param->sizes);
		mlx_key_hook(param->win_ptr, deal_key, param);
		mlx_loop(param->mlx_ptr);
		clear_mem(param, map);
	}
}
