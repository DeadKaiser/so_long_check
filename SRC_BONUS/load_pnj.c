/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_pnj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:26:57 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 00:38:09 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_img	*load_pnj_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*pnj;

	pnj = mlx_load_png("./Sprites/Pnj.png");
	if (!pnj)
		error_message("Problem with loading png pnj");
	img->pnj = mlx_texture_to_image(mlx, pnj);
	if (!img->pnj)
		error_message("Problem with texture to image");
	mlx_delete_texture(pnj);
	return (img);
}
