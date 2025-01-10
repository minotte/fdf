/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_diff_analyzer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:47:45 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/31 16:45:21 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	digit_diff_analyser(t_vars vars, t_dda dda)
{
	float	x;
	float	y;
	int		i;
	int		color;

	dda.l = fmax(fabsf(dda.x2 - dda.x1), fabsf(dda.y2 - dda.y1));
	dda.dx = (dda.x2 - dda.x1) / dda.l;
	dda.dy = (dda.y2 - dda.y1) / dda.l;
	x = dda.x1 + 0.5;
	y = dda.y1 + 0.5;
	i = 0;
	color = ft_color(dda);
	while (i < dda.l)
	{
		add_mlx_pixel_put (&vars, (x + vars.frame.midx_win),
			(y + vars.frame.midy_win), color);
		x = x + dda.dx;
		y = y + dda.dy;
		i++;
	}
}
