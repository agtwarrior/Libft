/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <davguerr@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 16:28:52 by david             #+#    #+#             */
/*   Updated: 2026/09/25 16:38:24 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextlst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nextlst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextlst;
	}
}
