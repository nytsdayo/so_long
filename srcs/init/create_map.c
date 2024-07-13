/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:59:00 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/12 17:13:50 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../../includes/draw.h"
#include "../../includes/games.h"

void	create_map(t_game *game, char *filename)
{
	game->map.body = read_map(filename);
	if (!game->map.body)
		return ;
	// printmap
	// for (int i = 0; game->map.body[i]; i++)
	// {
	// 	ft_printf("%s\n", game->map.body[i]);
	// }
	game->map.width = ft_cnt_col(game->map.body);
	game->map.height = ft_cnt_row(game->map.body);
	ft_printf("Map width: %d\n", game->map.width);
	ft_printf("Map height: %d\n", game->map.height);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	draw_map(game);
	ft_printf("Map created\n");
}
