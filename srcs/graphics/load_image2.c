/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:10:39 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/02 13:51:08 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_collectables(t_game *game)
{
	int	width;
	int	height;

	game->anim.collectables[0] = mlx_xpm_file_to_image(game->mlx,
			XPM_COLLECTABLES_0, &width, &height);
	game->anim.collectables[1] = mlx_xpm_file_to_image(game->mlx,
			XPM_COLLECTABLES_1, &width, &height);
	game->anim.collectables[2] = mlx_xpm_file_to_image(game->mlx,
			XPM_COLLECTABLES_2, &width, &height);
	game->anim.collectables[3] = mlx_xpm_file_to_image(game->mlx,
			XPM_COLLECTABLES_3, &width, &height);
}
