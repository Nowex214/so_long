/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:51:57 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/02 14:23:16 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls_h(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.wmap)
	{
		if (game->map.map[0][i] != '1')
			return (0);
		if (game->map.map[game->map.hmap - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls_v(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.hmap)
	{
		if (game->map.map[y][0] != '1')
			return (0);
		if (game->map.map[y][game->map.wmap - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	walls(t_game *game)
{
	int	v;
	int	h;

	v = check_walls_v(game);
	h = check_walls_h(game);
	if (!v || !h)
	{
		ft_printf("The map missing walls!\n");
		cleanup_and_exit(game);
	}
}

void	check_characters(t_game *game, int x, int y)
{
	if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0'
		&& game->map.map[y][x] != 'P' && game->map.map[y][x] != 'E'
		&& game->map.map[y][x] != 'X' && game->map.map[y][x] != 'C')
	{
		ft_printf("Error: Invalid character '%c'\n", game->map.map[y][x]);
		cleanup_and_exit(game);
	}
	if (game->map.map[y][x] == 'C')
		game->map.columncount++;
	if (game->map.map[y][x] == 'P')
		game->map.playercount++;
	if (game->map.map[y][x] == 'E')
		game->map.exitcount++;
}

void	characters_valid(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.hmap)
	{
		x = 0;
		while (x < game->map.wmap)
		{
			check_characters(game, x, y);
			x++;
		}
		y++;
	}
	if (!(game->map.playercount == 1 && game->map.columncount >= 1
			&& game->map.exitcount == 1))
	{
		ft_printf("Map is not valid!\n");
		cleanup_and_exit(game);
	}
}
