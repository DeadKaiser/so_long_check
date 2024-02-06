/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:22:19 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 17:03:05 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
t_img	*load_grass_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./Sprites/Grass.png");
	if (!grass)
		error_message("Problem with loading png grass");
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
		error_message("Problem with texture to image");
	mlx_delete_texture (grass);
	return (img);
}

t_img	*load_wall_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./Sprites/wall.png");
	if (!wall)
		error_message("Problem with loading png wall");
	img->wall = mlx_texture_to_image(mlx, wall);
	if (!img->wall)
		error_message("Problem with texture to image");
	mlx_delete_texture (wall);
	return (img);
}

t_img	*load_coin_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*coin;

	coin = mlx_load_png("./Sprites/coin.png");
	if (!coin)
		error_message("Problem with loading png coin");
	img->coin = mlx_texture_to_image(mlx, coin);
	if (!img->coin)
		error_message("Problem with texture to image");
	mlx_delete_texture(coin);
	return (img);
}

t_img	*load_exit_closed(mlx_t *mlx, t_img	*img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./Sprites/Exit_Closed.png");
	if (!exit)
		error_message("Problem with loading png exit close");
	img->exit_closed = mlx_texture_to_image(mlx, exit);
	if (!img->exit_closed)
		error_message("Problem with texture to image");
	mlx_delete_texture(exit);
	return (img);
}

