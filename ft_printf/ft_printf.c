/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 05:23:30 by rnakatan          #+#    #+#             */
/*   Updated: 2024/06/26 01:17:20 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_choice(const char chr, va_list args, int *out_len);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		out_len;
	int		i;

	out_len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_printf_choice(format[i], args, &out_len);
		}
		else
			ft_printf_putchar(format[i], &out_len);
		if (out_len < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (out_len);
}

static void	ft_printf_choice(const char chr, va_list args, int *out_len)
{
	if (chr == 'c')
		ft_printf_putchar(va_arg(args, int), out_len);
	else if (chr == 's')
		ft_printf_putstr(va_arg(args, char *), out_len);
	else if (chr == 'd' || chr == 'i' || chr == 'u' || chr == 'x' || chr == 'X')
		ft_printf_putnbr(va_arg(args, unsigned int), chr, out_len);
	else if (chr == 'p')
		ft_printf_putptr(va_arg(args, uintptr_t), out_len);
	else if (chr == '%')
		ft_printf_putchar('%', out_len);
	args++;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int				tmp;
// 	unsigned int	tmp2;
// 	int				num;

// 	num = 0;
// 	tmp = -3;
// 	tmp2 = 1132444142;
// 	ft_printf("ft_printf01: \001\002\007\v\010\f\r\n");
// 	printf("printf01: \001\002\007\v\010\f\r\n");
// 	ft_printf("ft_printf02: %d\n", ft_printf(""));
// 	printf("printf02: %d\n", printf(""));
// 	ft_printf("ft_printf03: %d\n", ft_printf("Hello, world\n"));
// 	printf("printf03: %d\n", printf("Hello, world\n"));
// 	ft_printf("ft_printf04: %d\n", ft_printf("Hello, %s\n", "world"));
// 	printf("printf04: %d\n", printf("Hello, %s\n", "world"));
// 	ft_printf("ft_printf05: %d\n", ft_printf("Hello, %c\n", 'c'));
// 	printf("printf05: %d\n", printf("Hello, %c\n", 'c'));
// 	ft_printf("ft_printf06: %d\n", ft_printf("Hello, %d\n", -42));
// 	printf("printf06: %d\n", printf("Hello, %d\n", -42));
// 	ft_printf("ft_printf07: %d\n", ft_printf("Hello, %i\n", tmp));
// 	printf("printf07: %d\n", printf("Hello, %i\n", tmp));
// 	ft_printf("ft_printf08: %d\n", ft_printf("Hello, %u\n", tmp2));
// 	printf("printf08: %d\n", printf("Hello, %u\n", tmp2));
// 	ft_printf("ft_printf09: %d\n", ft_printf("Hello, %jghoge\n", tmp2));
// 	printf("printf09: %d\n", printf("Hello, %jghoge\n", tmp2));
// 	ft_printf("ft_printf10: %d\n", ft_printf("Hello, %p\n", &tmp2));
// 	printf("printf10: %d\n", printf("Hello, %p\n", &tmp2));
// 	return (0);
// }
