/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <davguerr@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 16:42:18 by david             #+#    #+#             */
/*   Updated: 2026/09/25 17:02:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*ilist;
	void	*c;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		c = f(lst->content);
		ilist = ft_lstnew(c);
		if (!ilist)
		{
			del (c);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, ilist);
		lst = lst->next;
	}
	return (first);
}
