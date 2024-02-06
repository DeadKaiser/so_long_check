/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:46:36 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 16:32:40 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	string_to_screen(t_game *game)
{
	game->img->moves_print = mlx_put_string(game->mlx, "MOVES:",
			16, game->height * 64 - 44);
	mlx_image_to_window(game->mlx, game->img->coin,
		140, game->height * 64 - 50);
	mlx_put_string(game->mlx, ":", 160, game->height * 64 - 44);
}

void	print_moves(t_game *game)
{
	char	*string;

	string = ft_itoa(game->steps);
	mlx_delete_image(game->mlx, game->img->moves_nbr);
	game->img->moves_nbr = mlx_put_string(game->mlx, string,
			80, game->height * 64 - 44);
	free(string);
}

void	print_coins(t_game *game)
{
	char	*string;

	string = ft_itoa(game->collected + 1);
	mlx_delete_image(game->mlx, game->img->coin_nbr);
	game->img->coin_nbr = mlx_put_string(game->mlx, string,
			175, game->height * 64 -44);
	free(string);
}