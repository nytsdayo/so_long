/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:32:31 by rnakatan          #+#    #+#             */
/*   Updated: 2024/05/04 12:01:16 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_body(const char *str, char c, char **tab);
// static int	ft_split_body2(char **tab, size_t start, size_t i, size_t j);
static int	count_words(const char *str, char c);
static void	ft_split_free(char **tab, size_t len);

char	**ft_split(const char *str, char c)
{
	int		j;
	char	**tab;

	if (str == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	j = ft_split_body(str, c, tab);
	if (j == -1)
		return (NULL);
	tab[j] = NULL;
	return (tab);
}

static int	ft_split_body(const char *str, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			start = i;
			while (str[i] != c && str[i])
				i++;
			tab[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (tab[j] == NULL)
			{
				ft_split_free(tab, j);
				return (-1);
			}
			ft_strlcpy(tab[j++], str + start, (i - start + 1));
		}
		else
			i++;
	}
	return (j);
}

static int	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_split_free(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// old version
// char	**ft_split(const char *str, char c)
// {
// 	int		j;
// 	char	**tab;

// 	int		i;
// 	char	**tab2;
// 	if (str == NULL)
// 		return (NULL);
// 	tab = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1);
// 	if (tab == NULL)
// 		return (NULL);
// 	j = ft_split_body(str, c, tab);
// 	if (j == -1)
// 		return (NULL);
// tab2 = (char **)malloc(sizeof(char *) * (j + 1));
// if (tab2 == NULL)
// {
// 	ft_split_free(tab, j);
// 	return (NULL);
// }
// i = -1;
// while (++i < j)
// 	tab2[i] = tab[i];
// tab2[i] = NULL;
// free(tab);
// 	return (tab);
// }

// static int	ft_split_body2(char **tab, size_t start, size_t i, size_t j)
// {
// 	tab[j] = (char *)malloc(sizeof(char) * (i - start + 1));
// 	if (tab[j] == NULL)
// 	{
// 		ft_split_free(tab, j);
// 		return (-1);
// 	}
// 	return (1);
// }