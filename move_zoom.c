/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:52:19 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/25 12:04:04 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_vars vars, t_frame *frame, int keycode)
{
	if (keycode == LEFT)
		frame->midx_win -= 10;
	else if (keycode == RIGHT)
		frame->midx_win += 10;
	else if (keycode == UP)
		frame->midy_win -= 10;
	else if (keycode == DOWN)
		frame->midy_win += 10;
	vars.frame = *frame;
	to_print_line_ch(vars, *frame);
}

void	zoom(t_vars vars, t_frame *frame, int keycode)
{
	if (frame->zoom > 0 && keycode == ZM)
	{
		if (frame->zoom > 4)
			frame->zoom -= 2;
		else
			frame->zoom -= 0.5;
	}
	if (keycode == ZP)
	{
		if (frame->zoom < 2147483645.0)
		{
			if (frame->zoom > 4)
				frame->zoom += 2;
			else
				frame->zoom += 0.5;
		}
	}
	to_print_line_ch(vars, *frame);
}
