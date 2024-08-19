/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:38:39 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/07 04:02:14 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putnbr_case_int(unsigned int *num, int *out_len);
char	*ft_numstr_base(char flag);

void	ft_printf_putnbr(unsigned int num, char flag, int *out_len)
{
	unsigned int	temp;
	unsigned int	power;

	if (flag == 'i' || flag == 'd')
	{
		ft_printf_putnbr_case_int(&num, out_len);
		if (*out_len < 0 || (int)num == INT_MIN)
			return ;
	}
	temp = num;
	power = 1;
	while (temp / ft_printf_strlen(ft_numstr_base(flag)) > 0)
	{
		temp /= ft_printf_strlen(ft_numstr_base(flag));
		power *= ft_printf_strlen(ft_numstr_base(flag));
	}
	while (power)
	{
		ft_printf_putchar(ft_numstr_base(flag)[num / power], out_len);
		if (*out_len < 0)
			return ;
		num %= power;
		power /= ft_printf_strlen(ft_numstr_base(flag));
	}
}

void	ft_printf_putnbr_case_int(unsigned int *num, int *out_len)
{
	if ((int)*num == INT_MIN)
	{
		ft_printf_putstr("-2147483648", out_len);
		return ;
	}
	if ((int)*num < 0)
	{
		ft_printf_putchar('-', out_len);
		if (*out_len < 0)
			return ;
		*num *= -1;
	}
}

char	*ft_numstr_base(char flag)
{
	if (flag == 'i' || flag == 'd' || flag == 'u')
		return ("0123456789");
	else if (flag == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

void	ft_printf_putptr(uintptr_t ptr, int *out_len)
{
	uintptr_t	temp;
	uintptr_t	power;
	char		*numstr;

	numstr = ft_numstr_base('p');
	ft_printf_putstr(("0x"), out_len);
	if (*out_len == -1)
		return ;
	temp = ptr;
	power = 1;
	while (temp >= ft_printf_strlen(numstr))
	{
		temp /= ft_printf_strlen(numstr);
		power *= ft_printf_strlen(numstr);
	}
	while (power)
	{
		ft_printf_putchar(numstr[ptr / power], out_len);
		if (*out_len == -1)
			return ;
		ptr %= power;
		power /= ft_printf_strlen(numstr);
	}
}
