/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:00:22 by rnakatan          #+#    #+#             */
/*   Updated: 2024/05/03 04:12:18 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while ((*lst).next)
	{
		lst = (*lst).next;
	}
	return (lst);
}

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*last;

// 	lst = (t_list *)malloc(sizeof(t_list) * 3);
// 	lst[0].content = "first";
// 	lst[0].next = &lst[1];
// 	lst[1].content = "second";
// 	lst[1].next = &lst[2];
// 	lst[2].content = "third";
// 	lst[2].next = NULL;
// 	last = ft_lstlast(lst);
// 	printf("last->content: %s\n", (char *)last->content);
// 	return (0);
// }
