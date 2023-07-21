/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:18:34 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/11 20:18:35 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr_lst;

	ptr_lst = *lst;
	if (ptr_lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (ptr_lst->next)
	{
		ptr_lst = ptr_lst->next;
	}
	ptr_lst->next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
