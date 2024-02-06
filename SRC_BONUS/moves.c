/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:49:11 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 14:27:12 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	load_pnj(t_game *game, char dir)
{
	if (dir == 'u')
		mlx_draw_texture(game->img->pnj, game->pnj_up, 0, 0);
	if (dir == 'd')
		mlx_draw_texture(game->img->pnj, game->pnj_down, 0, 0);
	if (dir == 'r')
		mlx_draw_texture(game->img->pnj, game->pnj_right, 0, 0);
	if (dir == 'l')
		mlx_draw_texture(game->img->pnj, game->pnj_left, 0, 0);
}

void	move_select(t_game *game, char line, char dir)
{
	if (line == 'y')
	{
		if (dir == 'u')
			move_up(game);
		else
			move_down(game);
	}
	if (line == 'x')
	{
		if (dir == 'r')
			move_right(game);
		else
			move_left(game);
	}
}

void	move_player(t_game *game, char line, char dir)
{
	move_select(game, line, dir);
	load_pnj(game, dir);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'l');
}
