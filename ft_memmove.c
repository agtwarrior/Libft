/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <davguerr@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:15:21 by david             #+#    #+#             */
/*   Updated: 2026/09/24 17:28:24 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;
	size_t				i;

	p = dest;
	s = src;
	i = 0;
	if (p > s)
	{
		while (n > 0)
		{
			n--;
			p[n] = s[n];
		}
	}
	else if (p < s)
	{
		while (i < n)
		{
			p[i] = s[i];
			i++;
		}
	}
	return (dest);
}
