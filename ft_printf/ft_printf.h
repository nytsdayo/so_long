/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:07:23 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/19 13:43:05 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

void	ft_printf_putchar(char c, int *out_len);
void	ft_printf_putstr(char *str, int *out_len);

void	ft_printf_putnbr(unsigned int num, char flag, int *out_len);
void	ft_printf_putptr(uintptr_t ptr, int *out_len);

size_t	ft_printf_strlen(char *str);
size_t	ft_numlen(unsigned long long num, char flag);

#endif