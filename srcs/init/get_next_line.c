/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 07:47:55 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/20 22:46:55 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"

void	*return_null_and_free(char *char_a, char *char_b);
char	*ft_readline(int fd);
char	*ft_get_newline(char *line, char **save);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save = NULL;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	temp = ft_readline(fd);
	line = ft_strjoin(save, temp);
	if (!line)
		return (return_null_and_free(temp, NULL));
	free(temp);
	free(save);
	save = NULL;
	if (ft_strchr(line, '\n'))
		line = ft_get_newline(line, &save);
	if (line[0] == '\0')
		return (return_null_and_free(line, NULL));
	return (line);
}

void	*return_null_and_free(char *char_a, char *char_b)
{
	if (char_a)
	{
		free(char_a);
		char_a = NULL;
	}
	if (char_b)
	{
		free(char_b);
		char_b = NULL;
	}
	return (NULL);
}

char	*ft_readline(int fd)
{
	char	*line;
	char	*buf;
	int		rd_bytes;
	char	*temp;

	rd_bytes = 1;
	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (rd_bytes > 0 && !ft_strchr(line, '\n'))
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (return_null_and_free(line, NULL));
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes < 0)
			return (return_null_and_free(buf, line));
		buf[rd_bytes] = '\0';
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, buf);
		free(temp);
		free(buf);
	}
	return (line);
}

char	*ft_get_newline(char *line, char **save)
{
	int		j;
	char	*temp;

	j = 0;
	while (line[j] && line[j] != '\n')
		j++;
	*save = ft_strdup(&line[j + 1]);
	if (!*save)
		return (NULL);
	line[j + 1] = '\0';
	temp = ft_strdup(line);
	free(line);
	line = ft_strdup(temp);
	free(temp);
	return (line);
}
