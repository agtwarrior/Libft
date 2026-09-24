/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <davguerr@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:17:18 by david             #+#    #+#             */
/*   Updated: 2026/09/24 17:26:43 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*s;

	i = 0;
	p = dest;
	s = src;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dest);
}
