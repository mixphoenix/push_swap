/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:35:09 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/27 11:24:22 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sign(int x)
{
	if (x == '-' || x == '+')
		return (1);
	return (0);
}

int	ft_space(int x)
{
	if (x == 32)
		return (1);
	return (0);
}

int	isdigit(int c)
{
	unsigned char	x;

	x = (unsigned char) c;
	if (x >= 48 && x <= 57)
		return (1);
	return (0);
}

int	ft_check_max_int(char **av, int i)
{
	if ((ft_atoi(av[i]) > INT_MAX) || (ft_atoi(av[i]) < INT_MIN))
		ft_error();
	return (1);
}

int	check_args(char **av, int i, int j)
{
	while (av[i])
	{
		ft_check_max_int(av, i);
		j = 0;
		while (av[i][j])
		{
			if (ft_sign(av[i][j]))
			{
				j++;
				if (!isdigit(av[i][j]))
					return (0);
			}
			else if (isdigit(av[i][j]))
			{
				j++;
				if (av[i][j] == '\0')
					break ;
				if (!ft_space(av[i][j]) && !isdigit(av[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
