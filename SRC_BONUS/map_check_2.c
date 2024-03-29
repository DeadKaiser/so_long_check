/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:22:19 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 14:26:59 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_empty(char *map)
{
	size_t	i;

	i = 0;
	if (!map[i])
		error_message("Map is empty");
}

void	check_empty_lines(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
			error_message("Map contains empty lines");
		i++;
	}
}

void	check_horo(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->grid[0][i])
	{
		if (game->grid[0][i] != '1')
			error_message("The map is not surround by walls");
		if (game->grid[game->height -1][0] != '1')
			error_message("The map is not surrounded by walls");
		i++;
	}
}

void	check_vert(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->grid[i])
	{
		if (game->grid[i][0] != '1')
			error_message("The map is not surrounded by walls");
		if (game->grid[i][game->width -1] != '1')
			error_message("The map is not surrounded by walls");
		i++;
	}
}

void	check_walls(t_game *game)
{
	check_horo(game);
	check_vert(game);
}
