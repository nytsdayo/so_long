/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:32:25 by rnakatan          #+#    #+#             */
/*   Updated: 2024/05/03 04:52:38 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c2;

	i = 0;
	c2 = (char)c;
	while (s[i])
	{
		if ((char)s[i] == c2)
			return ((char *)&s[i]);
		i++;
	}
	if (c2 == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
