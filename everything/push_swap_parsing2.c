/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:37:48 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/19 04:02:06 by abmisk           ###   ########.fr       */
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

int	ft_check_args2(char **av)
{
	ft_check_alphargs(av);
	if (check_args(av, 1, 0))
		return (0);
	return (1);
}
