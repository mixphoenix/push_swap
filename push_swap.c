/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:40:41 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/25 00:26:23 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	ft_inisialize(t_stack **a, t_stack **b, int *i)
{
	*i = 1;
	*a = NULL;
	*b = NULL;
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	ft_inisialize(&a, &b, &i);
	if (ac > 1)
	{
		if (ft_check_args2(av))
			ft_error();
		while (i < ac)
		{
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
			i++;
		}
		if (check_duplicate(a))
			ft_error();
		if (check_if_num_are_sorted(a))
			return (0);
		if (ft_lstsize(a) <= 15)
			ft_sort_15_num(&a, &b);
		else
			ft_push_b_a(&a, &b, ft_push_a_b(&a, &b));
	}
	ft_free_stack(&a);
	return (0);
}
