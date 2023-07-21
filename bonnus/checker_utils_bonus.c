/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:06:46 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/15 05:10:02 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, "");
	ft_rotate(b, "");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_rrotate(a, "");
	ft_rrotate(b, "");
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_if_stack_sorted(t_stack *a)
{
	t_stack	*node;
	t_stack	*s;

	if (!a)
		return (0);
	node = a;
	s = a->next;
	while (node->next)
	{
		if (node->content > s->content)
			return (0);
		node = node->next;
		s = s->next;
	}
	return (1);
}
