/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:22:19 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 16:33:18 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	error_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	check_game_status(t_game *game)
{
	if (game->collected == game->coins)
	{
		if (mlx_image_to_window(game->mlx, game->img->exit_open,
				game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
			error_message("Failed to put image to window");
		game->grid[game->exit_y][game->exit_x] = '0';
		if (game->pnj_x == game->exit_x && game->pnj_y == game->exit_y)
		{
			mlx_close_window(game->mlx);
			ft_printf("Congratulations! You Win!\n");
		}
	}
}
