/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:32:02 by rnakatan          #+#    #+#             */
/*   Updated: 2024/05/04 02:21:31 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	i = dstlen;
	while (src[i - dstlen] && i < dstsize - 1)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	dst[i] = 0;
	return (dstlen + ft_strlen(src));
}
