/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:59:00 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/10 10:19:14 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"

void	create_map(t_game *game, char *filename)
{
	game->map.body = read_map(filename);
	if (!game->map.body)
		return ;
	game->map.width = ft_cnt_cols(game->map.body) - 1;
	game->map.height = ft_cnt_lines(game->map.body);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	draw_map(game);
}
