/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:55:43 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 16:38:32 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	check_path(t_game *temp, size_t y, size_t x)
{
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'C')
		temp->coins--;
	if (temp->grid[y][x] == 'E')
	{
		temp->exit_x = 1;
		return (0);
	}
	temp->grid[y][x] = '1';
	if (check_path(temp, y + 1, x))
		return (1);
	if (check_path(temp, y - 1, x))
		return (1);
	if (check_path(temp, y, x + 1))
		return (1);
	if (check_path(temp, y, x - 1))
		return (1);
	return (0);
}

void	flood_fill(t_game *game)
{
	t_game	temp;
	size_t	i;

	temp.height = game->height;
	temp.width = game->width;
	temp.coins = game->coins;
	temp.pnj_x = game->pnj_x;
	temp.pnj_y = game->pnj_y;
	temp.exit_x = 0;
	temp.grid = (char **)malloc(temp.height * sizeof(char *));
	if (!temp.grid)
		error_message("Memory allocation failed");
	i = 0;
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	check_path(&temp, temp.pnj_y, temp.pnj_x);
	if (!(temp.exit_x == 1 && temp.coins == 0))
		error_message("No valid path available");
	free_grid(temp.grid, temp.height);
}
