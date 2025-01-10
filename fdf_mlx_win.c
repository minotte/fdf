/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:12:09 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/31 16:36:04 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	if (x < WINDOW_WIDTH && y <= WINDOW_HEIGHT && x >= 0 && y >= 0)
	{
		dst = data->img.addr
			+ (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	close_all(t_vars *vars)
{
	free(vars->frame.point);
	if (vars->frame.p2)
		free(vars->frame.p2);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

t_vars	*ft_new_img(t_vars *vars)
{
	t_img	tmp;

	tmp.img = mlx_new_image(vars->mlx, vars->w_w, vars->w_h);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img = tmp;
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	return (vars);
}

int	key_what_do(int keycode, t_vars *vars)
{
	vars = ft_new_img(vars);
	if (keycode == ESC)
		close_all(vars);
	else if (keycode == TOP)
		top_view(*vars, &vars->frame);
	else if (keycode == ISO)
		to_print_line(*vars, vars->frame);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT
		|| keycode == RIGHT)
		ft_move(*vars, &vars->frame, keycode);
	else if (keycode == ZP || keycode == ZM)
		zoom(*vars, &vars->frame, keycode);
	else if (keycode == X || keycode == S || keycode == C || keycode == D
		|| keycode == Z || keycode == A)
		rotation(keycode, vars);
	return (0);
}

void	my_init_mlx(t_frame frame, char *title)
{
	t_vars	vars;

	vars.w_w = 1080;
	vars.w_h = 720;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return ;
	vars.win = mlx_new_window(vars.mlx, vars.w_w, vars.w_h, title);
	if (vars.win == NULL)
		return ;
	vars.img.img = mlx_new_image(vars.mlx, vars.w_w, vars.w_h);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	frame = distance(vars, frame);
	vars.frame = frame;
	to_print_line(vars, frame);
	mlx_hook(vars.win, 17, 0L, close_all, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_what_do, &vars);
	mlx_loop(vars.mlx);
	return ;
}
