/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:28:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/07 15:05:21 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **p_stack)
{
	t_stack	*second;

	if (ft_lstsize(*p_stack) < 2)
		return ;
	second = (*p_stack)->next;
	(*p_stack)->next = (*p_stack)->next->next;
	second->next = *p_stack;
	*p_stack = second;
}

void	operate_sa(t_stack **p_a)
{
	swap_stack(p_a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	operate_sb(t_stack **p_b)
{
	swap_stack(p_b);
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	operate_ss(t_stack **p_a, t_stack **p_b)
{
	swap_stack(p_a);
	swap_stack(p_b);
	ft_putendl_fd("ss", STDOUT_FILENO);
}
