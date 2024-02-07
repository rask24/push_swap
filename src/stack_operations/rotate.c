/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:05:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/07 15:05:17 by reasuke          ###   ########.fr       */
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

void	operate_ra(t_stack **p_a)
{
	rotate_stack(p_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	operate_rb(t_stack **p_b)
{
	rotate_stack(p_b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	operate_rr(t_stack **p_a, t_stack **p_b)
{
	rotate_stack(p_a);
	rotate_stack(p_b);
	ft_putendl_fd("rr", STDOUT_FILENO);
}
