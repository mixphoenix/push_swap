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
		str = ft_split(av[i], ' ');
		if (!str[0])
			ft_error();
		j = 0;
		while(str[j])
		{
			num = ft_atoi(str[j]);
			ft_lstadd_back(&a, ft_lstnew(num));
			j++;
		}
		ft_str_free(str);
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
		//system("leaks push_swap");
		//print_stack(a);
		if (check_duplicate(a))
			ft_error();
		if (check_if_num_are_sorted(a))
		{
			ft_free_stack(&a);
			return (0);
		}
		if (ft_lstsize(a) <= 15)
			ft_sort_15_num(&a, &b);
		else
			ft_push_b_a(&a, &b, ft_push_a_b(&a, &b));
	}
	ft_free_stack(&a);
	return (0);
}
