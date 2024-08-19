/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:31:31 by rnakatan          #+#    #+#             */
/*   Updated: 2024/05/03 03:57:31 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// #include <string.h>

// int	main(void)
// {
// 	char *s = "teste";
// 	char c = 'e';
// 	printf("ft_strrchr: %p\n", ft_strrchr(s, c));
// 	printf("strrchr: %p\n", strrchr(s, c));
// 	return (0);
// }