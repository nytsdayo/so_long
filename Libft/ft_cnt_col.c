/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:55:38 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/19 07:32:32 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_cnt_col(char **strs)
{
	size_t	cnt;
	size_t	top;

	top = ft_strlen(strs[0]);
	cnt = 1;
	while (strs[cnt])
	{
		if (ft_strlen(strs[cnt]) != top)
			return (0);
		cnt++;
	}
	cnt++;
	return (top);
}
