/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:37:48 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/26 16:43:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	isalpha(int c)
{
	unsigned char	x;

	x = (unsigned char) c;
	if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
		return (1);
	return (0);
}

void	ft_check_alphargs(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (isalpha(av[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}

char	**ft_quote(char **av)
{
	int		i;
	char	*s;
	char	**str;

	s = malloc(sizeof(av));
	i = 1;
	while (av[i])
	{
		if (!ft_(av[i]))
		{
			free(s);
			ft_error();
		}
		s = f_strjoin(f_strjoin(s, " "), av[i++]);
	}
	str = ft_split(s, ' ');
	free(s);
	return (str);
}


int	ft_check_args2(char **av)
{
	char **args;

	args = ft_quote(av);
	ft_check_alphargs(args);
	if (check_args(args, 1, 0))
		return (0);
	return (1);
}
