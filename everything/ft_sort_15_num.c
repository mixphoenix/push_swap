/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_15_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:24:46 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/13 02:42:19 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max(t_stack *a)
{
	int	i;
	int	max;
	int	indx;

	max = a->content;
	i = 0;
	indx = 0;
	while (a)
	{
		if (max < a->content)
		{
			max = a->content;
			indx = i;
		}
		a = a->next;
		i++;
	}
	return (indx);
}

int	ft_min(t_stack *a)
{
	int	i;
	int	min;
	int	indx;

	i = 0;
	min = a->content;
	indx = 0;
	while (a)
	{
		if (min > a->content)
		{
			min = a->content;
			indx = i;
		}
		a = a->next;
		i++;
	}
	return (indx);
}

void	ft_sort_3_num(t_stack **a)
{
	int	min;
	int	max;

	if (check_if_num_are_sorted(*a))
		return ;
	max = ft_max(*a);
	min = ft_min(*a);
	if (min == 1)
	{
		if (max == 2)
			ft_swap(a, "sa\n");
		else
			ft_rotate(a, "ra\n");
	}
	if (min == 0)
	{
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
	}
	if (min == 2)
	{
		if (max == 0)
			ft_swap(a, "sa\n");
		ft_rrotate(a, "rra\n");
	}
}

void	ft_check_to_sort_15(t_stack **a, t_stack **b, int mid)
{
	int	min;
	int	n;

	min = ft_min(*a);
	n = get_n(*a, min);
	if (min <= mid)
	{
		while (*a && (*a)->content != n)
			ft_rotate(a, "ra\n");
		ft_push(a, b, "pb\n");
	}
	else if (min > mid)
	{
		while (*a && (*a)->content != n)
			ft_rrotate(a, "rra\n");
		ft_push(a, b, "pb\n");
	}
}

void	ft_sort_15_num(t_stack **a, t_stack **b)
{
	int	mid;

	mid = ft_lstsize(*a) / 2;
	while (ft_lstsize(*a) > 3)
		ft_check_to_sort_15(a, b, mid);
	ft_sort_3_num(a);
	while (ft_lstsize(*b))
		ft_push(b, a, "pa\n");
}
