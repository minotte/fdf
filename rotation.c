/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:11:21 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/31 16:52:45 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_z(t_frame frame)
{
	int		i;
	float	x_tmp;
	double	teta;

	i = 0;
	teta = frame.angz * (M_PI / 180);
	while (i < (frame.h * frame.w))
	{
		x_tmp = frame.p2[i].x;
		frame.p2[i].x = frame.p2[i].x * cos(teta) - frame.p2[i].y * sin(teta);
		frame.p2[i].y = x_tmp * sin(teta) + frame.p2[i].y * cos(teta);
		frame.p2[i].z = frame.p2[i].z;
		i++;
	}
}

void	rot_y(t_frame frame)
{
	int		i;
	double	teta;
	float	x_tmp;

	i = 0;
	teta = frame.angy * (M_PI / 180);
	while (i < (frame.h * frame.w))
	{
		x_tmp = frame.p2[i].x;
		frame.p2[i].x = frame.p2[i].x * cos(teta) + frame.p2[i].z * sin(teta);
		frame.p2[i].z = (x_tmp * (-sin(teta))) + frame.p2[i].z * cos(teta);
		frame.p2[i].y = frame.p2[i].y;
		i++;
	}
}

void	rot_x(t_frame frame)
{
	int		i;
	double	teta;
	float	tmp;

	i = 0;
	teta = frame.angx * (M_PI / 180);
	while (i < (frame.h * frame.w))
	{
		tmp = frame.p2[i].z;
		frame.p2[i].x = frame.p2[i].x;
		frame.p2[i].z = frame.p2[i].y * sin(teta) + frame.p2[i].z * cos(teta);
		frame.p2[i].y = frame.p2[i].y * cos(teta) - (tmp * sin(teta));
		i++;
	}
}

void	rotation(int keycode, t_vars *vars)
{
	if (keycode == X || keycode == S)
	{
		if (keycode == S)
			vars->frame.angx = -2;
		else
			vars->frame.angx = 2;
		rot_x(vars->frame);
	}
	else if (keycode == C || keycode == D)
	{
		if (keycode == D)
			vars->frame.angy = -2;
		else
			vars->frame.angy = 2;
		rot_y(vars->frame);
	}
	else if (keycode == Z || keycode == A)
	{
		if (keycode == A)
			vars->frame.angz = -2;
		else
			vars->frame.angz = 2;
		rot_z(vars->frame);
	}
	to_print_line_ch(*vars, vars->frame);
}
