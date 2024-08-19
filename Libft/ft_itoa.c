/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:33:45 by rnakatan          #+#    #+#             */
/*   Updated: 2024/05/02 08:44:13 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_body(int n, int len);

char	*ft_itoa(int n)
{
	int	len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	else
		len = 0;
	return (ft_itoa_body(n, len));
}

static char	*ft_itoa_body(int n, int len)
{
	char	*str;
	int		tmp;

	tmp = n;
	while (tmp > 0)
	{
		len++;
		tmp /= 10;
	}
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (str[0] == '0' && str[1])
		str[0] = '-';
	return (str);
}
