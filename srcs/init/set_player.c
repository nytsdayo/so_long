/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:24:29 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/10 10:45:44 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"
#include "../../includes/games.h"
#include "../../includes/player.h"

void	set_player(t_player *player, t_point point, void *asset)
{
	ft_printf("set player start\n");
	(void)point;
	player->point = point;
	ft_printf("set player point\n");
	ft_printf("set player point.x: %d\n", player->point.x);
	ft_printf("set player point.y: %d\n", player->point.y);
	player->cnt_collectibles = 0;
	player->cnt_moves = 0;
	player->asset = asset;
	ft_printf("set player end\n");
}
