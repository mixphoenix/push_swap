/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:30:44 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/15 05:32:23 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack **a, char *p)
{
	t_stack	*node;
	int		s;

	if (ft_lstsize(*a) > 1)
	{
		node = (*a)->next;
		s = (*a)->content;
		(*a)->content = node->content;
		node->content = s;
		ft_printf("%s", p);
	}
}

void	ft_rotate(t_stack **a, char *p)
{
	t_stack	*node;

	if (ft_lstsize(*a) > 1)
	{
		node = *a;
		*a = (*a)->next;
		node->next = NULL;
		ft_lstadd_back(a, node);
		ft_printf("%s", p);
	}
}

void	ft_rrotate(t_stack **a, char *p)
{
	t_stack	*node;
	t_stack	*node1;
	int		i;

	i = 0;
	node = NULL;
	node1 = NULL;
	node = *a;
	if (*a && ft_lstsize(*a) > 1)
	{
		while (node->next && node->next->next)
			node = node->next;
		node1 = node->next;
		node->next = NULL;
		ft_lstadd_front(a, node1);
		ft_printf("%s", p);
	}
}

void	ft_push(t_stack **a, t_stack **b, char *p)
{
	t_stack	*node;

	node = *a;
	*a = (*a)->next;
	node->next = NULL;
	ft_lstadd_front(b, node);
	ft_printf("%s", p);
}
