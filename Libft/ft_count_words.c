/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:46:34 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/19 08:07:29 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s1, char *s2)
{
	int	cnt;
	int	check_cnt;
	int	i;
	int	j;

	cnt = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		check_cnt = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				check_cnt++;
			else
				break ;
			if (check_cnt == (int)ft_strlen(s2))
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}
