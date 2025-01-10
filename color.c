/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:24:26 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/25 12:39:52 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_color_z(t_dda dda)
{
	int	color;

	if (dda.z1 == 0 && dda.z2 == 0)
		color = 0xFFFFFF;
	if (dda.z1 > 0 || dda.z2 > 0)
		color = 0xFF0000;
	else if (dda.z1 < 0 || dda.z2 < 0)
		color = 0x0000FF;
	return (color);
}

int	ft_color(t_dda dda)
{
	int	color;

	if (dda.color1)
		color = dda.color1;
	else if (dda.color2)
		color = dda.color2;
	else
		color = ft_color_z(dda);
	return (color);
}
