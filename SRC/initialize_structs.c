/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:53:00 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 17:09:02 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*initialize_game_struct(char **grid)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_message("struct memory allocation failed");
	game->width = ft_strlen(grid[0]);
	game->height = row_count(grid);
	game->grid = grid;
	game->steps = 1;
	game->coins = count_coins(game);
	game->pnj_x = get_pnj_pos(game, 'x');
	game->pnj_y = get_pnj_pos(game, 'y');
	game->exit_x = get_exit_pos (game, 'x');
	game->exit_y = get_exit_pos (game, 'y');
	return (game);
}

t_game	*initialize_data(char *map)
{
	char	*map_as_str;
	char	**map_as_array;
	t_game	*data;

	map_as_str = read_map(map);
	check_empty(map_as_str);
	check_empty_lines(map_as_str);
	check_map_content(map_as_str);
	map_as_array = ft_split(map_as_str, '\n');
	check_map_shape(map_as_array);
	data = initialize_game_struct(map_as_array);
	check_walls(data);
	flood_fill(data);
	free (map_as_str);
	return (data);
}

t_img	*initialize_img_struct(mlx_t *mlx)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_grass_texture(mlx, assets);
	assets = load_wall_texture(mlx, assets);
	assets = load_coin_texture(mlx, assets);
	assets = load_pnj_texture(mlx, assets);
	assets = load_exit_closed(mlx, assets);
	return (assets);
}
