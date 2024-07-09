/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:10:39 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/09 21:03:20 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"

void	read_map(int fd, t_map *map)
{
	int	i;

	if (fd < 0)
		return ;
	map->body = malloc(sizeof(char *) * 1);
	if (!map->body)
		return ;
	i = 0;
	map->body[i] = get_next_line(fd);
	while (map->body[i] != NULL)
	{
		i++;
		map->body = ft_realloc(map->body, sizeof(char *) * (i + 1));
		if (!map->body)
			return ;
		map->body[i] = get_next_line(fd);
		if (!map)
			return ;
	}
	close(fd);
}
