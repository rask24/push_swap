/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:05:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 16:56:39 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*second;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
}

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*before_last;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	before_last = ft_lst_before(*stack, last);
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	operate_ra(t_list **stack_a)
{
	rotate_stack(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	operate_rra(t_list **stack_a)
{
	reverse_rotate_stack(stack_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}
