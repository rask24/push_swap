/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:56:53 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 17:02:11 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_list **stack_1, t_list **stack_2)
{
	t_list	*stack_1_first;

	if (!*stack_1)
		return ;
	stack_1_first = *stack_1;
	*stack_1 = (*stack_1)->next;
	stack_1_first->next = NULL;
	ft_lstadd_front(stack_2, stack_1_first);
}

void	operate_pa(t_list **stack_b, t_list **stack_a)
{
	push_stack(stack_b, stack_a);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	operate_pb(t_list **stack_a, t_list **stack_b)
{
	push_stack(stack_a, stack_b);
	ft_putendl_fd("pb", STDOUT_FILENO);
}
