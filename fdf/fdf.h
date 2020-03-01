/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 23:16:35 by lulee             #+#    #+#             */
/*   Updated: 2020/01/29 23:59:23 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define X_START 1000.0
# define Y_START 400.0
# define COEF 21
# define ESC 53
# define C 8
# define ONE 18
# define TWO 19
# define Z 6
# define X 7
# define L 37
# define R 15
# define U 32
# define D 2
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_TOP 126
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_coord_pixel
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_pix;

typedef	struct	s_magnitudes_str
{
	int	count_line;
	int	max_dot;
	int	*dot_line;
}				t_sizes;

typedef	struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map_line;
	t_sizes sizes;
	t_pix	*coord;
	int		play_z;
	int		zoom;
	int		angle;
}				t_param;

typedef	struct	s_brez
{
	int	x0;
	int y0;
	int x1;
	int y1;
	int delta_x;
	int delta_y;
	int sign;
	int sign_x;
	int sign_y;
	int flag;
}				t_brez;

void			ft_print_error(void);
char			**read_file(char *argv, char *map_line);
int				ft_pow(int pow);
int				parse_to_10(char *tmp, int i);
void			color_and_z(char *tmp, t_pix *coord, int count);
t_pix			*share_map(char **map, t_pix *coord, t_sizes *sizes);
void			draw_line(t_brez *line, t_param *param, int color);
double			move_x(int i, t_param *param);
int				color_grad(int c1, int c2);
void			print_pict(t_param *param);
int				deal_key(int key, t_param *param);
int				key_part_four(int key, t_param *param);
int				calculation_x0(t_param *param, int i, int j);
int				calculation_x1_hor(t_param *param, int i, int j);
int				calculation_x1_vert(t_param *param, int i, int j);
int				calculation_y0(t_param *param, int i, int j);
int				calculation_y1_hor(t_param *param, int i, int j);
int				calculation_y1_vert(t_param *param, int i, int j);
void			init_brez(t_brez *line, t_param *param, int i, int j);

#endif
