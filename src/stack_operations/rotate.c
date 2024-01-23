/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:05:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/23 16:23:22 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **p_stack)
{
	t_stack	*second;
	t_stack	*last;

	if (ft_lstsize(*p_stack) < 2)
		return ;
	second = (*p_stack)->next;
	last = ft_lstlast(*p_stack);
	last->next = *p_stack;
	(*p_stack)->next = NULL;
	*p_stack = second;
}

void	reverse_rotate_stack(t_stack **p_stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (ft_lstsize(*p_stack) < 2)
		return ;
	last = ft_lstlast(*p_stack);
	before_last = ft_lst_before(*p_stack, last);
	before_last->next = NULL;
	last->next = *p_stack;
	*p_stack = last;
}

void	operate_ra(t_stack **p_a)
{
	rotate_stack(p_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	operate_rra(t_stack **p_a)
{
	reverse_rotate_stack(p_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	operate_rb(t_stack **p_b)
{
	rotate_stack(p_b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}
