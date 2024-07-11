/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:10:39 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/10 01:45:14 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"

char	**read_map(char *filename)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 1);
	if (!map)
		return (NULL);
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i] != NULL)
	{
		i++;
		map = ft_realloc(map, sizeof(char *) * (i + 1));
		if (map == NULL)
			return (NULL);
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}