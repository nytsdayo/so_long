/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:33:15 by rnakatan          #+#    #+#             */
/*   Updated: 2024/05/02 03:05:42 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	i = -1;
	if (dst_cpy == src_cpy)
		return (dst);
	if (dst_cpy < src_cpy)
	{
		while (++i < len)
			dst_cpy[i] = src_cpy[i];
	}
	else
	{
		while (len > 0)
		{
			dst_cpy[len - 1] = src_cpy[len - 1];
			len--;
		}
	}
	return (dst);
}
