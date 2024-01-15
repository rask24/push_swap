/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rorate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:05:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 14:22:40 by reasuke          ###   ########.fr       */
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
