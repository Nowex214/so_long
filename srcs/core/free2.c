/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:24:13 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/02 14:36:27 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_idle_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->anim.idle_l[i])
			mlx_destroy_image(game->mlx, game->anim.idle_l[i]);
		if (game->anim.idle_r[i])
			mlx_destroy_image(game->mlx, game->anim.idle_r[i]);
		i++;
	}
}

void	destroy_walk_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->anim.walk_l[i])
			mlx_destroy_image(game->mlx, game->anim.walk_l[i]);
		if (game->anim.walk_r[i])
			mlx_destroy_image(game->mlx, game->anim.walk_r[i]);
		i++;
	}
}
