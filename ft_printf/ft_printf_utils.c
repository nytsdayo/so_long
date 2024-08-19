/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:41:58 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/07 04:02:41 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_numlen(unsigned long long num, char flag)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= flag;
		len++;
	}
	return (len);
}

void	ft_printf_putchar(char c, int *out_len)
{
	int	tmp;

	tmp = write(1, &c, 1);
	if (tmp < 0)
		*out_len = -1;
	else
		*out_len += tmp;
}

void	ft_printf_putstr(char *str, int *out_len)
{
	int	tmp;

	if (!str)
	{
		tmp = write(1, "(null)", 6);
		if (tmp < 0)
			*out_len = -1;
		else
			*out_len += tmp;
		return ;
	}
	tmp = write(1, str, ft_printf_strlen(str));
	if (tmp < 0)
		*out_len = -1;
	else
		*out_len += tmp;
}
