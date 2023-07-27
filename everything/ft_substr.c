/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:11:53 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/27 21:24:08 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	if (c == '\0')
		return (p + ft_strlen(s));
	while (*p)
	{
		if (*p == (char) c)
			return (p);
		p++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	i = 0;
	substring = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	if (!substring)
		return (NULL);
	while (s[start] != '\0' && ft_strlen(s) >= start && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

void	ft_str_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	x;

	if (size && (count > SIZE_MAX / size))
		return (NULL);
	x = count * size;
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	return (ft_memset(p, 0, x));
}
