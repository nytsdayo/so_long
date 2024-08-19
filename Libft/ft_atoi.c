/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:34:43 by rnakatan          #+#    #+#             */
/*   Updated: 2024/05/04 16:14:18 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
static int	overflow(int mnsflag, long res, const char c);
static int	jugde_flag(char nptr);

int	ft_atoi(const char *nptr)
{
	int		i;
	int		mnsflag;
	long	res;

	i = 0;
	res = 0;
	mnsflag = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		mnsflag = jugde_flag(nptr[i++]);
	while (nptr[i] == '0')
		i++;
	if (ft_isdigit(nptr[i]) == 0 || nptr[i] == '0')
		return (0);
	while (ft_isdigit(nptr[i]))
	{
		if (overflow(mnsflag, res, nptr[i]) == 0)
			return (0);
		else if (overflow(mnsflag, res, nptr[i]) == -1)
			return (-1);
		res = res * 10 + (nptr[i++] - '0');
	}
	return (res * mnsflag);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	overflow(int mnsflag, long res, const char c)
{
	if ((res * mnsflag > LONG_MAX / 10 || (res * mnsflag == LONG_MAX / 10 && (c
					- '0') > LONG_MAX - res * mnsflag * 10)) || res
		* mnsflag < LONG_MIN / 10 || (res * mnsflag == LONG_MIN / 10 && -(c
				- '0') < LONG_MIN - res * mnsflag * 10))
	{
		if (mnsflag == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

static int	jugde_flag(char nptr)
{
	if (nptr == '-')
		return (-1);
	else
		return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str;

// 	str = "-9223372036854775817";
// 	// L
// 	char *str2 = "-9223372036854775807";
// 	char *str3 = "22223372036854775815";
// 	char *str4 = "9223372036854775819";
// 	printf("atoi: %d\n", atoi(str));
// 	printf("atoi: %d\n", atoi(str2));
// 	printf("atoi: %d\n", atoi(str3));
// 	printf("atoi: %d\n", atoi(str4));
// 	printf("ft_atoi: %d\n", ft_atoi(str));
// 	printf("ft_atoi: %d\n", ft_atoi(str2));
// 	printf("ft_atoi: %d\n", ft_atoi(str3));
// 	printf("ft_atoi: %d\n", ft_atoi(str4));
// 	return (0);
// }