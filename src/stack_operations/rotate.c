/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:05:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/23 15:11:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*second;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
}

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	before_last = ft_lst_before(*stack, last);
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	operate_ra(t_stack **stack_a)
{
	rotate_stack(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	operate_rra(t_stack **stack_a)
{
	reverse_rotate_stack(stack_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}
