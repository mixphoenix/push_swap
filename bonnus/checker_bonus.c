/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:13:22 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/19 05:14:29 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	ft_err(void)
{
	ft_printf("Error\n");
	return (0);
}

void	check_to_b_push(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*b) > 0)
		ft_push(b, a, "");
}

int	ft_do_input(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n"))
		ft_swap(a, "");
	else if (ft_strcmp(line, "sb\n"))
		ft_swap(b, "");
	else if (ft_strcmp(line, "ra\n"))
		ft_rotate(a, "");
	else if (ft_strcmp(line, "rb\n"))
		ft_rotate(b, "");
	else if (ft_strcmp(line, "rra\n"))
		ft_rrotate(a, "");
	else if (ft_strcmp(line, "rrb\n"))
		ft_rrotate(b, "");
	else if (ft_strcmp(line, "pa\n"))
		check_to_b_push(a, b);
	else if (ft_strcmp(line, "pb\n"))
		ft_push(a, b, "");
	else if (ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else if (ft_strcmp(line, "rr\n"))
		rr(a, b);
	else
		return (ft_err());
	return (1);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*line;
	int		x;

	line = get_next_line(0);
	while (line > 0)
	{
		x = ft_do_input(a, b, line);
		if (x == 0)
		{
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
	if (ft_check_if_stack_sorted(*a) && ft_lstsize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	if (ac > 1)
	{
		if (ft_check_args2(av))
			ft_error ();
		while (i < ac)
		{
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
			i++;
		}
		if (check_duplicate(a))
			ft_error();
		if (check_if_num_are_sorted(a))
			return (ft_printf("u have a sequence of sorted numbers.\n"));
		checker(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
