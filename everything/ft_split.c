/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:11:50 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/27 21:11:51 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	ft_getsize(const char *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			size++;
		i++;
	}
	return (size);
}

int	ft_getlen_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

int	ft_addstr(char **strs, const char *s, char c, int i)
{
	int	j;
	int	len_word;

	j = 0;
	while (s[j] && s[j] == c)
		j++;
	len_word = ft_getlen_word((s + j), c);
	strs[i] = ft_substr(s, j, len_word);
	if (!strs[i])
		return (0);
	return (j + len_word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		n_words;
	int		i;
	int		pos;
	int		tmp;

	if (!s)
		return (NULL);
	n_words = ft_getsize(s, c);
	strs = ft_calloc((n_words + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	i = -1;
	pos = 0;
	while (++i < n_words)
	{
		tmp = ft_addstr(strs, s + pos, c, i);
		if (!tmp)
		{
			ft_free_strs(strs);
			return (NULL);
		}
		pos += tmp;
	}
	return (strs);
}
