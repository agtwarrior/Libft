/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <davguerr@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:09:34 by david             #+#    #+#             */
/*   Updated: 2026/09/25 11:02:41 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
	{
		len++;
	}
	return (len);
}

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

static void	*free_all(char	**text, size_t	j)
{
	while (j > 0)
	{
		j--;
		free(text[j]);
	}
	free(text);
	return (NULL);
}

static char	**fill_words(char **text, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			len = word_len(&s[i], c);
			text[j] = ft_substr(s, i, len);
			if (!text[j])
				return (free_all(text, j));
			i = i + len;
			j++;
		}
	}
	text[j] = NULL;
	return (text);
}

char	**ft_split(char const *s, char c)
{
	char	**text;

	if (!s)
		return (NULL);
	text = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!text)
		return (NULL);
	return (fill_words(text, s, c));
}
