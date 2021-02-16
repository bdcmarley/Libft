/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 11:46:16 by cmarley           #+#    #+#             */
/*   Updated: 2020/04/29 11:46:16 by cmarley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int		ft_words_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		*leak(char **final, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(final[i]);
		i++;
	}
	free(final);
	return (NULL);
}

static char		**ft_splitter(char const *s, int words, char c, char **final)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = ft_words_len(s, c);
		if (!(final[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (leak(final, i));
		j = 0;
		while (j < len)
			final[i][j++] = *s++;
		final[i][j] = '\0';
	}
	final[i] = NULL;
	return (final);
}

char			**ft_split(char	const *s, char c)
{
	char	**final;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(final = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	final = ft_splitter(s, words, c, final);
	return (final);
}
