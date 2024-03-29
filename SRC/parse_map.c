/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:22:19 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 16:38:08 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	row_count(char **grid)
{
	size_t	y;

	y = 0;
	while (grid[y])
		y++;
	return (y);
}

size_t	count_coins(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	i = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'C')
			{
				i++;
			}
			x++;
		}
		y++;
	}
	return (i);
}

char	*read_map(char *map)
{
	char	*line;
	char	*line_joined;
	int		fd;

	fd = open(map, O_RDONLY);
	line_joined = ft_calloc(1, 1);
	if (!line_joined)
		return (NULL);
	while (1)
	{
		line = get_next_line (fd);
		if (line)
		{
			line_joined = ft_strjoin(line_joined, line);
			free(line);
		}
		else
			break ;
	}
	close (fd);
	return (line_joined);
}
