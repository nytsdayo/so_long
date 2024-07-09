/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:59:00 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/09 23:51:36 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"

void	create_map(t_game *game, char *filename)
{
	game->map = malloc(sizeof(t_map));
	read_map(open(filename, O_RDONLY), game->map);
	ft_printf("flag1\n");
	if (!game->map)
		return ;
	game->map->width = ft_cnt_cols(game->map->body) - 1;
	game->map->height = ft_cnt_lines(game->map->body);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	ft_printf("flag2\n");
	draw_map(game);
}
