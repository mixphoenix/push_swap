/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:40:41 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/27 12:24:53 by mac              ###   ########.fr       */
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

void print_stack(t_stack *a)
{
	while (a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\n");
}

t_stack *stack_create(int ac, t_stack *a, char **av)
{
	int num;
	int i;
	int j;
	char **str;
	
	num = 0;
	i = 1;
	while (i < ac)
	{
		if(ft_strchr(av[i], ' '))
		{
			str = ft_split(av[i], ' ');
			j = 0;
			while(str[j])
			{
				num = ft_atoi(str[j]);
				ft_lstadd_back(&a, ft_lstnew(num));
				j++;
			}
			ft_str_free(str);
		}
		else
		{
			num = ft_atoi(av[i]);
			ft_lstadd_back(&a, ft_lstnew(num));
		}
		i++;
	}
	return (a);
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
		a = stack_create(ac, a, av);
		//print_stack(a);
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
