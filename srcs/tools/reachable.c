/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:59:49 by ehenry            #+#    #+#             */
/*   Updated: 2025/01/02 20:03:58 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long"

void	flood_fill(char **map, int y, int x, t_flood_fill start)
{
	t_flood_fill	stack[y * x];
	t_flood_fill	cur;
	int				top;

	top = 0;
	stack[top++] = start;
	while (top > 0)
	{
		cur = stack[--top];
		if (cur.x < 0 || cur.x >= x || cur.y < 0 || cur.y >= y)
			continue;
		if (map[cur.y][map.x] != '0' && map[cur.y][cur.x] != 'C')
			continue;
		map[cur.y][cur.x] = 'F';
		stack[top++] = (t_flood_fill){cur.x + 1, cur.y};
		stack[top++] = (t_flood_fill){cur.x - 1, cur.y};
		stack[top++] = (t_flood_fill){cur.x, cur.y + 1};
		stack[top++] = (t_flood_fill){cur.x, cur.y - 1};
	}
}

int	check_map_validity(t_game *game)
{
	int				x;
	int				y;
	t_flood_fill	start;

	start.x = game->player.player_x;
	start.y = game->player.player_y;
	flood_fill(game->map.map, game->map.wmap, game->map.hmap, start);
	y = 0;
	while (y < game->map.hmap)
	{
		x = 0;
		while (x < game->map.wmap)
		{
			if (game->map.map[y][x] == 'C')
				return (0);
			if (game->map.map[y][x] == 'F')
				game->map.map[y][x] = '0';
			x++;
		}
		y++;
	}
	return (1);
}
