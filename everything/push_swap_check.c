/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:28:18 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/27 16:16:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_if_num_are_sorted(t_stack *a)
{
	t_stack	*node;

	if (ft_lstsize(a) <= 1)
		exit(0);
	node = a->next;
	while (node && a)
	{
		if (node->content < a->content)
			return (0);
		node = node->next;
		a = a->next;
	}
	return (1);
}

int	check_duplicate(t_stack *a)
{
	t_stack	*node;

	node = a;
	while (node)
	{
		a = node->next;
		while (a)
		{
			if (node->content == a->content)
				return (1);
			a = a->next;
		}
		node = node->next;
	}
	return (0);
}

int	ft_if_existe(t_stack *a, int b)
{
	while (a)
	{
		if (a->content == b)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_sort_b_a(t_stack **a, t_stack **b, t_var *all)
{
	if ((*b)->content == all->s[all->indx])
	{
		ft_push(b, a, "pa\n");
		all->indx--;
	}
	else
	{
		if (all->bottom == 0 || ((*b)->content > ft_bottom(*a)))
		{
			ft_push(b, a, "pa\n");
			ft_rotate(a, "ra\n");
			all->bottom++;
		}
		else
		{
			if (get_indx(*b, all->s[all->indx]) < (ft_lstsize(*b) / 2))
				ft_rotate(b, "rb\n");
			else
				ft_rrotate(b, "rrb\n");
		}
	}
}
