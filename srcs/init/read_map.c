/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:10:39 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/09 20:05:33 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"

char	**read_map(int fd)
{
	char	**map;
	int		i;

	if (fd < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * 1);
	if (!map)
		return (NULL);
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i] != NULL)
	{
		i++;
		map = ft_realloc(map, sizeof(char *) * (i + 1));
		map[i] = get_next_line(fd);
		if (!map)
			return (NULL);
	}
	close(fd);
	return (map);
}
