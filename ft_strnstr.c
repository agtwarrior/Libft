/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <davguerr@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:48:27 by david             #+#    #+#             */
/*   Updated: 2026/09/24 18:39:31 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	equal(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && to_find[i] && str[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (to_find[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		if (str[i] == to_find[j])
		{
			if ((equal (&str[i], &to_find[j], n - i)) == 1)
			{
				return ((char *)&str[i]);
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
