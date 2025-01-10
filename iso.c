/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:47:13 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/31 16:51:57 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_b(t_frame frame)
{
	int		i;
	float	teta;
	float	tmp;

	i = 0;
	teta = frame.angz * (M_PI / 180);
	while (i < (frame.h * frame.w))
	{
		tmp = frame.p2[i].x;
		frame.p2[i].x = frame.p2[i].x * cos(teta) - frame.p2[i].y * sin(teta);
		frame.p2[i].y = tmp * sin(teta) + frame.p2[i].y * cos(teta);
		frame.p2[i].z = frame.p2[i].z;
		i++;
	}
	i = 0;
	teta = frame.angy * (M_PI / 180);
	while (i < (frame.h * frame.w))
	{
		tmp = frame.point[i].x;
		frame.p2[i].x = frame.p2[i].x * cos(teta) + frame.p2[i].z * sin(teta);
		frame.p2[i].z = (tmp * (-sin(teta))) + frame.p2[i].z * cos(teta);
		frame.p2[i].y = frame.p2[i].y;
		i++;
	}
}

t_frame	iso(t_frame frame)
{
	int		i;
	float	teta;
	float	tmp;

	i = 0;
	frame = init_zoom_ang(frame);
	teta = frame.angx * (M_PI / 180);
	while (i < (frame.h * frame.w))
	{	
		tmp = frame.point[i].z;
		frame.p2[i].z = frame.point[i].y * sin(teta)
			+ frame.point[i].z * cos(teta);
		frame.p2[i].y = frame.point[i].y * cos(teta) - (tmp * sin(teta));
		frame.p2[i].x = frame.point[i].x;
		i++;
	}
	iso_b(frame);
	return (frame);
}
