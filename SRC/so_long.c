/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:22:19 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 14:19:28 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	t_img		*images;

	if (argc != 2)
		error_message("Please, you just have to put one file");
	check_file_extension(argv[1]);
	game = initialize_data(argv[1]);
	game->mlx = mlx_init(game->width * PIXELS,
			game->height * PIXELS, "so_long", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	images = initialize_img_struct(game->mlx);
	game->img = images;
	fill_background(game);
	render_map(game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
