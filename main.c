/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:02:27 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/19 11:55:49 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fdf.h"

void	fdf_open(t_frame frame, int fd, char *title)
{
	char	*line;
	char	**word;
	int		check;
	int		i;

	i = 0;
	check = 1;
	line = get_next_line(fd);
	while (check == 1)
	{
		word = ft_split(line, ' ');
		create_point(word, i, frame);
		ft_clear(line, word);
		line = get_next_line(fd);
		if (line == NULL)
			check = 0;
		i++;
	}
	my_init_mlx(frame, title);
	close(fd);
}

t_frame	fdf_open_check(int fd)
{
	char	*line;
	char	**word;
	int		check;
	t_frame	frame;

	frame.h = 0;
	frame.w = -2;
	line = get_next_line(fd);
	check_file(fd, line);
	check = 1;
	word = NULL;
	while (check == 1)
	{
		word = ft_split(line, ' ');
		if (frame.w != -1)
			frame.w = is_rectangle(word, frame.w);
		frame.h = frame.h + 1;
		ft_clear(line, word);
		line = get_next_line(fd);
		if (line == NULL)
			check = 0;
	}
	close(fd);
	return (frame);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_point	*point;
	t_point	*p2;
	t_frame	frame;

	if (argc != 2)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (ft_checkext(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		frame = fdf_open_check(fd);
		if (frame.w == -1)
			return (1);
		point = malloc(sizeof(t_point) * (frame.h * frame.w));
		p2 = malloc(sizeof(t_point) * (frame.h * frame.w));
		frame.point = point;
		frame.p2 = p2;
		fd = open(argv[1], O_RDONLY);
		fdf_open(frame, fd, argv[1]);
	}
	return (0);
}
