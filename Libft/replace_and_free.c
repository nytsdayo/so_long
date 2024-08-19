/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:47:01 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/08 22:03:34 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*replace_and_free(void *new_ptr, void *old_ptr)
{
	if (old_ptr)
		free(old_ptr);
	return (new_ptr);
}

// int	main(void)
// {
// 	char *str = ft_strdup("Hello, World!");
// 	char *new_str = ft_strdup("Goodbye, World!");
// 	printf("str: %s\n", str);
// 	str = replace_and_free(new_str, str);
// 	printf("str: %s\n", str);
// 	free(str);
// 	return (0);
// }