/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:24:29 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/13 14:02:49 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../../includes/draw.h"
#include "../../includes/games.h"
#include "../../includes/player.h"

void	set_player(t_game *game, t_point point, void *asset)
{
	t_player	player;
	int			i;
	char		correct_c[2];

	correct_c[0] = COLLECTIBLE;
	correct_c[1] = '\0';
	player = game->player;
	player.point = point;
	i = 0;
	while (i < game->map.height)
	{
		ft_printf("game->map.body[i]: %s\n", game->map.body[i]);
		player.cnt_collectibles += ft_count_words(game->map.body[i], correct_c);
		i++;
	}
	player.cnt_moves = 0;
	player.asset = asset;
	game->player = player;
	ft_printf("set player end\n");
}
