/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_to_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:42:52 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/31 16:43:43 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_condition_top(int i, t_vars vars, t_frame *frame, t_dda dda)
{
	if ((i % frame->w) < (frame->w - 1))
	{
		dda.x2 = frame->point[i + 1].x * frame->col_l;
		dda.y2 = frame->point[i + 1].y * frame->col_l;
		dda.z2 = frame->point[i + 1].z;
		dda.color2 = frame->point[i + 1].color;
		digit_diff_analyser(vars, dda);
	}
	if ((i >= (frame->w)))
	{
		dda.x2 = dda.x1;
		dda.y2 = frame->point[i - frame->w].y * frame->col_l;
		dda.z2 = frame->point[i - frame->w].z;
		dda.color2 = frame->point[i - frame->w].color;
		digit_diff_analyser(vars, dda);
	}
}

void	top_view(t_vars vars, t_frame *frame)
{
	int		i;
	t_dda	dda;

	i = 0;
	frame->midx_win = (vars.w_w / 2);
	frame->midy_win = (vars.w_h / 2);
	frame->zoom = frame->col_l;
	while (i < (frame->h * frame->w))
	{
		frame->p2[i].x = frame->point[i].x;
		frame->p2[i].y = frame->point[i].y;
		frame->p2[i].z = frame->point[i].z;
		frame->p2[i].color = frame->point[i].color;
		dda.x1 = frame->point[i].x * frame->col_l;
		dda.y1 = frame->point[i].y * frame->col_l;
		dda.z1 = frame->point[i].z;
		dda.color1 = frame->point[i].color;
		ft_condition_top(i, vars, frame, dda);
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}

void	ft_condition(int i, t_vars vars, t_frame frame, t_dda dda)
{
	if ((i % frame.w) < (frame.w - 1))
	{
		dda.x2 = frame.p2[i + 1].x * frame.zoom;
		dda.y2 = (frame.p2[i + 1].y) * frame.zoom;
		dda.z2 = frame.p2[i + 1].z;
		dda.color2 = frame.point[i + 1].color;
		digit_diff_analyser(vars, dda);
	}
	if ((i >= (frame.w)))
	{
		dda.x2 = (frame.p2[i - frame.w].x * frame.zoom);
		dda.y2 = (frame.p2[i - frame.w].y * frame.zoom);
		dda.z2 = (frame.p2[i - frame.w].z);
		dda.color2 = frame.point[i - frame.w].color;
		digit_diff_analyser(vars, dda);
	}
}

void	to_print_line(t_vars vars, t_frame frame)
{
	int		i;
	t_dda	dda;

	i = 0;
	frame = iso(frame);
	while (i < (frame.h * frame.w))
	{
		dda.x1 = (frame.p2[i].x) * frame.zoom;
		dda.y1 = (frame.p2[i].y) * frame.zoom;
		dda.z1 = frame.p2[i].z;
		dda.color1 = frame.point[i].color;
		ft_condition(i, vars, frame, dda);
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}

void	to_print_line_ch(t_vars vars, t_frame frame)
{
	int		i;
	t_dda	dda;

	i = 0;
	while (i < (frame.h * frame.w))
	{
		dda.x1 = (frame.p2[i].x) * frame.zoom;
		dda.y1 = (frame.p2[i].y) * frame.zoom;
		dda.z1 = frame.p2[i].z;
		dda.color1 = frame.point[i].color;
		ft_condition(i, vars, frame, dda);
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}
