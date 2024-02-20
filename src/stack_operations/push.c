/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:56:53 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:15:37 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	push_stack(t_stack **p_s1, t_stack **p_s2)
{
	t_stack	*s1_first;

	if (!*p_s1)
		return ;
	s1_first = *p_s1;
	*p_s1 = (*p_s1)->next;
	s1_first->next = NULL;
	ft_lstadd_front(p_s2, s1_first);
}

void	operate_pa(t_stack **p_b, t_stack **p_a)
{
	push_stack(p_b, p_a);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	operate_pb(t_stack **p_a, t_stack **p_b)
{
	push_stack(p_a, p_b);
	ft_putendl_fd("pb", STDOUT_FILENO);
}
