/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:11:45 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/27 21:11:46 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_bottom(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->content);
}

void	ft_get_update(t_var *all)
{
	all->start = all->start - all->offs;
	if (all->start < 0)
		all->start = 0;
	all->end = all->end + all->offs;
	if (all->end > all->nsize - 1)
		all->end = all->nsize - 1;
}

t_var	*ft_push_a_b(t_stack **a, t_stack **b)
{
	t_var	*all;

	all = ft_get_var(*a);
	while (ft_lstsize(*a))
	{
		ft_get_update(all);
		while (ft_lstsize(*b) != (all->end - all->start + 1))
		{
			if ((*a)->content >= all->s[all->start]
				&& (*a)->content <= all->s[all->end])
			{
				ft_push(a, b, "pb\n");
				if ((*b)->content < all->s[all->mid])
					ft_rotate(b, "rb\n");
			}
			else
				ft_rotate(a, "ra\n");
		}
	}
	return (all);
}

void	ft_push_b_a(t_stack **a, t_stack **b, t_var *all)
{
	all->bottom = 0;
	while (all->indx >= 0)
	{
		if (ft_if_existe((*b), all->s[all->indx]))
			ft_sort_b_a(a, b, all);
		else
		{
			if (all->bottom > 0)
			{
				ft_rrotate(a, "rra\n");
				all->bottom--;
				all->indx--;
			}
		}
	}
	free(all->s);
	free(all);
}
