/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:39:14 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/31 16:44:15 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct s_cam {
	float	x;
	float	y;
	float	z;
	float	zoom;
}	t_cam;

typedef struct s_point {
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_frame {
	int		w;
	int		h;
	int		line_l;
	int		col_l;
	float	zoom;
	float	angx;
	float	angy;
	float	angz;
	int		center_x;
	int		center_y;
	float	midx_win;
	float	midy_win;
	t_point	*point;
	t_point	*p2;
}	t_frame;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		w_w;
	int		w_h;
	t_img	img;
	t_frame	frame;
}	t_vars;

typedef struct s_dda
{
	int		l;
	float	dx;
	float	dy;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	z1;
	float	z2;
	int		color1;
	int		color2;
}	t_dda;

/* WINDOW*/
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720

/* keycode*/
# define ESC 65307
# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define TOP 116
# define ISO 121
# define Q 119
# define CTRL  65507
# define Z 122
# define X 120
# define C 99
# define A 97
# define S 115
# define D 100
# define ZP 65451
# define ZM 65453

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP,
	ON_MOUSEDOWN,
	ON_MOUSEUP,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		main(int argc, char **argv);
int		is_rectangle(char **word, int check);
int		ft_checkext(char *title);
void	check_file(int fd, char *line);
void	ft_clear(char *line, char **word);
void	my_init_mlx(t_frame frame, char *title);
void	add_mlx_pixel_put(t_vars *data, int x, int y, int color);
void	print_point_frame(t_vars vars, t_frame frame);
t_frame	create_point(char **word, int line_nb, t_frame frame);
void	to_print_line(t_vars vars, t_frame frame);
void	to_print_line_ch(t_vars vars, t_frame frame);
void	top_view(t_vars vars, t_frame *frame);
int		close_all(t_vars *vars);
int		ft_color(t_dda dda);
t_frame	distance(t_vars vars, t_frame frame);
void	rot_z(t_frame frame);
void	rot_y(t_frame frame);
void	rot_x(t_frame frame);
t_frame	iso(t_frame frame);
void	zoom(t_vars vars, t_frame *frame, int key);
void	ft_move(t_vars vars, t_frame *frame, int keycode);
t_frame	init_zoom_ang(t_frame frame);
t_vars	*ft_new_img(t_vars *vars);
void	rotation(int keycode, t_vars *vars);
void	digit_diff_analyser(t_vars vars, t_dda dda);

#endif
