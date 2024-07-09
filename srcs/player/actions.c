/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:a+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:25:30 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/08 23:09:11 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

void	press_ESC(t_game *game)
{
	printf("Exit game\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

// void	move_forward(t_game *game)
// {
// 	printf("Move forward\n");
// }

// void	move_backward(t_game *game)
// {
// 	printf("Move backward\n");
// }

// void	move_left(t_game *game)
// {
// 	printf("Move left\n");
// }

// void	move_right(t_game *game)
// {
// 	printf("Move right\n");
// }
