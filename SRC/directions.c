/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:53:00 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 17:08:07 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_coin(t_game *game, int y, int x)
{
	int	coin_i;

	coin_i = 0;
	x = x * 64 + 16;
	y = y * 64 + 16;
	while (coin_i < game->img->coin->count)
	{
		if (game->img->coin->instances[coin_i].x == x
			&& game->img->coin->instances[coin_i].y == y)
		{
			game->img->coin->instances[coin_i].enabled = false;
		}
		coin_i++;
	}
}

t_game	*move_up(t_game *game)
{
	if (game->grid[game->pnj_y - 1][game->pnj_x] != '1'
		&& game->grid[game->pnj_y - 1][game->pnj_x] != 'E')
	{
		if (game->grid[game->pnj_y - 1][game->pnj_x] == 'C')
		{
			remove_coin(game, game->pnj_y - 1, game->pnj_x);
			game->grid[game->pnj_y - 1][game->pnj_x] = '0';
			game->collected += 1;
		}
		game->pnj_y -= 1;
		game->img->pnj->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->grid[game->pnj_y + 1][game->pnj_x] != '1'
		&& game->grid[game->pnj_y + 1][game->pnj_x] != 'E')
	{
		if (game->grid[game->pnj_y + 1][game->pnj_x] == 'C')
		{
			remove_coin(game, game->pnj_y + 1, game->pnj_x);
			game->grid[game->pnj_y + 1][game->pnj_x] = '0';
			game->collected += 1;
		}
		game->pnj_y += 1;
		game->img->pnj->instances[0].y += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->grid[game->pnj_y][game->pnj_x + 1] != '1'
		&& game->grid[game->pnj_y][game->pnj_x + 1] != 'E')
	{
		if (game->grid[game->pnj_y][game->pnj_x + 1] == 'C')
		{
			remove_coin(game, game->pnj_y, game->pnj_x + 1);
			game->grid[game->pnj_y][game->pnj_x + 1] = '0';
			game->collected += 1;
		}
		game->pnj_x += 1;
		game->img->pnj->instances[0].x += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->grid[game->pnj_y][game->pnj_x - 1] != '1'
		&& game->grid[game->pnj_y][game->pnj_x - 1] != 'E')
	{
		if (game->grid[game->pnj_y][game->pnj_x - 1] == 'C')
		{
			remove_coin(game, game->pnj_y, game->pnj_x - 1);
			game->grid[game->pnj_y][game->pnj_x - 1] = '0';
			game->collected += 1;
		}
		game->pnj_x -= 1;
		game->img->pnj->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}
