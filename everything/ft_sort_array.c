/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:39:34 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/27 16:12:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_var	*ft_get_var(t_stack *a)
{
	t_var	*all;

	all = (t_var *) malloc(sizeof(t_var));
	all->nsize = ft_lstsize(a);
	all->s = ft_sorted_arr(a);
	all->indx = ft_lstsize(a) - 1;
	all->mid = ft_lstsize(a) / 2;
	all->n = (all->nsize <= 150 && all->nsize > 10) * 8
		+ (all->nsize > 150) * 18;
	all->offs = all->nsize / (all->n);
	all->start = all->mid;
	all->end = all->mid;
	return (all);
}

int	get_n(t_stack *a, int indx)
{
	int	i;

	i = 0;
	while (a)
	{
		if (i == indx)
			return (a->content);
		a = a->next;
		i++;
	}
	return (0);
}

int	get_indx(t_stack *a, int n)
{
	int	indx;

	indx = 0;
	while (a)
	{
		if (a->content == n)
			return (indx);
		a = a->next;
		indx++;
	}
	return (0);
}

int	*ft_sorted_arr(t_stack *a)
{
	int	i;
	int	l;
	int	*s;

	i = 0;
	l = ft_lstsize(a);
	s = (int *) malloc(sizeof(int) * l);
	while (a)
	{
		s[i] = a->content;
		i++;
		a = a->next;
	}
	ft_sort_array(s, l);
	return (s);
}

void	ft_sort_array(int *s, int l)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (i < l)
	{
		j = 0;
		while ((i + j) < l)
		{
			if (s[i] > s[i + j])
			{
				x = s[i];
				s[i] = s[i + j];
				s[i + j] = x;
			}
			j++;
		}
		i++;
	}
}
