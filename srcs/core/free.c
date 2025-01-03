/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:07:53 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/02 14:24:46 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_collectable_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->anim.collectables[i])
			mlx_destroy_image(game->mlx, game->anim.collectables[i]);
		i++;
	}
}

void	destroy_animations(t_game *game)
{
	destroy_idle_images(game);
	destroy_walk_images(game);
	destroy_collectable_images(game);
}

void	destroy_map_images(t_game *game)
{
	if (game->map.ground)
		mlx_destroy_image(game->mlx, game->map.ground);
	if (game->map.wall)
		mlx_destroy_image(game->mlx, game->map.wall);
	if (game->map.door_open)
		mlx_destroy_image(game->mlx, game->map.door_open);
	if (game->map.door_close)
		mlx_destroy_image(game->mlx, game->map.door_close);
	if (game->map.enemy)
		mlx_destroy_image(game->mlx, game->map.enemy);
	if (game->map.dead)
		mlx_destroy_image(game->mlx, game->map.dead);
	if (game->map.hud)
		mlx_destroy_image(game->mlx, game->map.hud);
}

void	destroy_window_and_display(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.hmap)
	{
		if (game->map.map[i])
			free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	game->map.map = NULL;
}
