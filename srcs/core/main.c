/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:15:18 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/02 20:07:21 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_errors(t_game *game)
{
	walls(game);
	characters_valid(game);
}

int	combined_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	update_player_animation(game);
	collectabes_loop(game);
	move_enemies(game);
	display_move_collectables(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Try: ./so_long <map_file>\n");
		return (1);
	}
	if (!check_map_validity(game))
	{
		ft_printf("Map is invalid: some collectables are not reachable\n")
	}
	if (!initialize_game(&game, av))
	{
		ft_printf("Failed to initialize the game.\n");
		return (1);
	}
	check_errors(&game);
	setup_game(&game);
	mlx_key_hook(game.win, input, &game);
	mlx_loop_hook(game.mlx, combined_loop, &game);
	mlx_loop(game.mlx);
	cleanup_and_exit(&game);
	return (0);
}
