/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:56:53 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 16:15:33 by reasuke          ###   ########.fr       */
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
