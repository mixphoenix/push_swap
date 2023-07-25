/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:53:21 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/25 00:41:59 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}t_stack;

typedef struct s_var
{
	int	max;
	int	min;
	int	mid;
	int	offs;
	int	nsize;
	int	n;
	int	start;
	int	bottom;
	int	end;
	int	*s;
	int	indx;
}t_var;

t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *next);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_var	*ft_get_var(t_stack *a);
void	ft_lstadd_back(t_stack **lst, t_stack *next);
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_free_stack(t_stack **a);
int		ft_printf(const char *arr, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
long	int	ft_atoi(const char *str);
int		ft_hex(unsigned int n, char x);
int		ft_putunbr(unsigned int nb);
int		ft_pointer(unsigned long long p);
int		ft_print(int c, const char *arr, int i, va_list args);
int		*ft_sorted_arr(t_stack *a);
int		get_indx(t_stack *a, int n);
int		ft_hex_p(unsigned long long n);
void	ft_error(void);
void	ft_sort_array(int *s, int size);
void	ft_rotate(t_stack **a, char *p);
void	ft_swap(t_stack **a, char *p);
void	ft_rrotate(t_stack **a, char *p);
void	ft_push(t_stack **a, t_stack **b, char *p);
int		ft_bottom(t_stack *a);
void	ft_get_update(t_var *all);
int		check_duplicate(t_stack *a);
int		check_if_num_are_sorted(t_stack *a);
t_var	*ft_push_a_b(t_stack **a, t_stack **b);
int		ft_if_existe(t_stack *a, int b);
void	ft_sort_b_a(t_stack **a, t_stack **b, t_var *all);
void	ft_push_b_a(t_stack **a, t_stack **b, t_var *all);
void	ft_check_alphargs(char **av);
int		ft_check_args2(char **av);
int		isalpha(int c);
int		check_args(char **av, int i, int j);
int		isdigit(int c);
int		ft_space(int x);
void	ft_sort_15_num(t_stack **a, t_stack **b);
void	ft_sort_3_num(t_stack **a);
int		ft_min(t_stack *a);
int		ft_sign(int x);
int		ft_max(t_stack *a);
int		get_n(t_stack *a, int indx);
int		ft_checker(t_stack **a, t_stack **b, char *line);
int		ft_strcmp(char *s1, char *s2);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
int		ft_err(void);
int		ft_check_if_stack_sorted(t_stack *a);
void	check_to_push(t_stack **a, t_stack **b, char *par);
int		ft_check_max_int(char **av, int i);

#endif
