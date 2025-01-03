/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:54:57 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/02 14:36:29 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	initialize_game(t_game *game, char **av)
{
	if (!init_mlx_and_map(game, av))
		return (0);
	init_camera_dimensions(game);
	if (!init_window(game))
		return (0);
	game->player.last_direction = 'R';
	init_enemies(game);
	load_game(game);
	return (1);
}

int	init_mlx_and_map(t_game *game, char **av)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: Unable to initialize mlx.\n");
		return (0);
	}
	if (!read_map(game, av[1]))
	{
		cleanup_and_exit(game);
		return (0);
	}
	return (1);
}

void	init_camera_dimensions(t_game *game)
{
	if (game->map.wmap * 96 > WIN_WIDTH)
		game->cam.win_width = WIN_WIDTH;
	else
		game->cam.win_width = game->map.wmap * 96;
	if (game->map.hmap * 96 > WIN_HEIGHT)
		game->cam.win_height = WIN_HEIGHT;
	else
		game->cam.win_height = game->map.hmap * 96;
	game->cam.cam_x = 0;
	game->cam.cam_y = 0;
}

int	init_window(t_game *game)
{
	if (game->cam.win_width <= 0 || game->cam.win_height <= 0)
	{
		ft_printf("Error: Invalid window dimensions.\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->cam.win_width,
			game->cam.win_height, "So_long ehenry");
	if (!game->win)
	{
		ft_printf("Error: Unable to create window.\n");
		return (0);
	}
	return (1);
}
