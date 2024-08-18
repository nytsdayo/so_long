/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:56:45 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/19 08:33:46 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"

char	**copy_map(char **map);
int		is_not_outwall(t_position pos, char **map);
int		separate_check(char **map, t_player player);
void	flood_fill(char **check_map, t_position pos);

int	is_invalid_map(t_game *game, char **map)
{
	t_position	map_pos;
	char		c;

	map_pos = (t_position){0, 0};
	while (map[map_pos.y])
	{
		map_pos.x = 0;
		while (map[map_pos.y][map_pos.x])
		{
			c = map[map_pos.y][map_pos.x];
			if (is_not_outwall(map_pos, map) || (c != WALL && c != FLOOR
					&& c != COLLECTIBLE && c != GOAL && c != PLAYER))
				return (1);
			map_pos.x++;
		}
		map_pos.y++;
	}
	if (separate_check(map, game->player))
		return (1);
	return (0);
}

int	is_not_outwall(t_position pos, char **map)
{
	if (pos.x == 0 || pos.y == 0 || !map[pos.y + 1] || !map[pos.y][pos.x + 1])
	{
		if (map[pos.y][pos.x] != WALL)
			return (1);
	}
	return (0);
}

int	separate_check(char **map, t_player player)
{
	char		**check_map;
	t_position	map_pos;

	check_map = ft_calloc(ft_cnt_row(map), sizeof(char *) * ft_cnt_row(map));
	if (!check_map)
		return (1);
	check_map = copy_map(map);
	flood_fill(check_map, player.point);
	map_pos = (t_position){0, 0};
	while (check_map[map_pos.y])
	{
		map_pos.x = 0;
		while (check_map[map_pos.y][map_pos.x])
		{
			if (check_map[map_pos.y][map_pos.x] == FLOOR
				|| check_map[map_pos.y][map_pos.x] == GOAL
				|| check_map[map_pos.y][map_pos.x] == COLLECTIBLE)
				return (free_map(check_map), 1);
			map_pos.x++;
		}
		map_pos.y++;
	}
	return (free_map(check_map), 0);
}

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = ft_calloc(ft_cnt_row(map), sizeof(char *) * ft_cnt_row(map));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (free_map(copy), NULL);
		i++;
	}
	return (copy);
}

void	flood_fill(char **map, t_position pos)
{
	if (pos.x < 0 || pos.y < 0 || !map[pos.y] || !map[pos.y][pos.x])
		return ;
	if (map[pos.y][pos.x] == PLAYER || map[pos.y][pos.x] == FLOOR
		|| map[pos.y][pos.x] == GOAL || map[pos.y][pos.x] == COLLECTIBLE)
	{
		map[pos.y][pos.x] = ',';
		flood_fill(map, (t_position){pos.x + 1, pos.y});
		flood_fill(map, (t_position){pos.x - 1, pos.y});
		flood_fill(map, (t_position){pos.x, pos.y + 1});
		flood_fill(map, (t_position){pos.x, pos.y - 1});
	}
}
