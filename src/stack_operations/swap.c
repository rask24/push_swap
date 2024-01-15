/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:28:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 16:56:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **stack)
{
	t_list	*second;

	if (ft_lstsize(*stack) < 2)
		return ;
	second = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	second->next = *stack;
	*stack = second;
}

void	operate_sa(t_list **stack_a)
{
	swap_stack(stack_a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}
