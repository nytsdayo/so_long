/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:24:29 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/10 02:26:47 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"
#include "../../includes/games.h"
#include "../../includes/player.h"

void	set_player(t_game *game, t_point point, void *asset)
{
	game->player->point->x = point.x;
	game->player->point->y = point.y;
	game->player->cnt_collectibles = 0;
	game->player->cnt_moves = 0;
	game->player->asset = asset;
}
