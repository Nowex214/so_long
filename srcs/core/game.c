/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:05:17 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/02 13:56:48 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_game(t_game *game)
{
	count_collectables(game);
	find_player(game);
	load_idle_left(game);
	load_idle_right(game);
	load_walk_left(game);
	load_walk_right(game);
	load_collectables(game);
	update_camera(game);
}

int	setup_game(t_game *game)
{
	int	height;
	int	width;

	load_images(game);
	height = 0;
	while (height < game->map.hmap)
	{
		width = 0;
		while (game->map.map[height][width])
		{
			if (add_graphics(game, height, width) == -1)
				return (-1);
			width++;
		}
		height++;
	}
	mlx_hook(game->win, 17, 0, (void *)cleanup_and_exit, game);
	return (0);
}

void	cleanup_and_exit(t_game *game)
{
	destroy_animations(game);
	destroy_map_images(game);
	destroy_window_and_display(game);
	free_map(game);
	if (game->enemies)
		free(game->enemies);
	free(game->mlx);
	exit(0);
}
