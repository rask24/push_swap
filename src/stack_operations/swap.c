/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:28:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/23 15:11:33 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*second;

	if (ft_lstsize(*stack) < 2)
		return ;
	second = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	second->next = *stack;
	*stack = second;
}

void	operate_sa(t_stack **stack_a)
{
	swap_stack(stack_a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	operate_sb(t_stack **stack_b)
{
	swap_stack(stack_b);
	ft_putendl_fd("sb", STDOUT_FILENO);
}
