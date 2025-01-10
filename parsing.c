/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:24:53 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/10 15:26:38 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_checkext(char *title)
{
	int	i;

	i = 0;
	while (title[i])
	{
		if (i != 0 && title[i] == '.' && title[i + 1] == 'f'
			&& title[i + 2] == 'd' && title[i + 3] == 'f'
			&& title[i + 4] == '\0')
			return (1);
		i++;
	}
	ft_putendl_fd("Error, I need a file with .fdf as extension", 2);
	exit(0);
}

void	check_file(int fd, char *line)
{
	if (fd < 0)
	{
		ft_putendl_fd("this file doesn't exist", 2);
		exit (0);
	}
	if (!line)
	{
		ft_putendl_fd("this file is empty", 2);
		exit (0);
	}
}

void	ft_clear(char *line, char **word)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (word[i])
	{
		free(word[i]);
		i++;
	}
	free(word);
	free(line);
}

int	is_rectangle(char **word, int check)
{
	int	i;

	i = 0;
	while (word[i])
		i++;
	if (i > 0 && word[i - 1][0] == '\n')
		i--;
	if ((i == 0) || (i != check && check != -2))
	{
		ft_putendl_fd("Error, your map is not good", 2);
		i = -1;
	}
	return (i);
}
