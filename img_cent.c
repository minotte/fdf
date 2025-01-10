/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_cent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:36:47 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/25 11:59:48 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_frame	good_place(t_frame frame, int mid)
{
	int	i;
	int	all;

	all = frame.h * frame.w;
	i = 0;
	while (i < all)
	{
		frame.point[i].z = frame.point[i].z / 4;
		frame.point[i].color = frame.point[i].color;
		if (i != mid)
		{
			frame.point[i].x = frame.point[i].x - frame.point[mid].x;
			frame.point[i].y = frame.point[i].y - (frame.h / 2);
		}
		i++;
	}
	frame.point[mid].x = frame.point[mid].x - frame.point[mid].x;
	if (frame.h % 2)
		frame.point[mid].y = frame.point[mid].y - frame.point[mid].y;
	else
		frame.point[mid].y = frame.point[mid].y - frame.point[mid].y - 1;
	return (frame);
}

t_frame	init_zoom_ang(t_frame frame)
{
	frame.angx = 45;
	frame.angy = 15;
	frame.angz = -25;
	return (frame);
}

t_frame	distance(t_vars vars, t_frame frame)
{
	int	mid;

	if (frame.h % 2)
		mid = (frame.w * frame.h) / 2;
	else
		mid = (frame.w * frame.h) / 2 - (frame.w / 2);
	frame.line_l = vars.w_w / (frame.w + 2);
	frame.col_l = vars.w_h / (frame.h + 2);
	frame.center_x = frame.point[mid].x;
	frame.center_y = frame.point[mid].y;
	frame.zoom = 10;
	frame = init_zoom_ang(frame);
	frame.midx_win = (vars.w_w / 2) - frame.center_x;
	frame.midy_win = (vars.w_h / 2) - frame.center_y;
	good_place(frame, mid);
	return (frame);
}

t_frame	create_point_col(char **word, t_frame frame, int i)
{
	int		j;
	char	**w_color;

	j = 0;
	w_color = ft_split(word[i % frame.w], ',');
	frame.point[i].z = ft_atoi(w_color[0]);
	if (w_color[1][0] == '0' && w_color[1][0] == '0')
	frame.point[i].color = ft_atoi_color(w_color[1]);
	else
		frame.point[i].color = 0xFFFFFF;
	while (w_color[j])
	{
		free(w_color[j]);
		j++;
	}
	free(w_color);
	return (frame);
}

t_frame	create_point(char **word, int line_nb, t_frame frame)
{
	int	i;

	i = line_nb * frame.w;
	while (i < ((line_nb + 1) * frame.w))
	{
		frame.point[i].x = (float)(i % frame.w);
		frame.point[i].y = (float)line_nb;
		if (ft_strchr(word[i % frame.w], ','))
			frame = create_point_col(word, frame, i);
		else
		{
			frame.point[i].z = ft_atoi(word[i % frame.w]);
			frame.point[i].color = 0xFFFFFF;
		}
		if (frame.point[i].z > 2000)
			frame.point[i].z = 2000;
		if (frame.point[i].z < -2000)
			frame.point[i].z = -2000;
		i++;
	}
	return (frame);
}
