/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:18:15 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/07 15:04:58 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack **p_stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (ft_lstsize(*p_stack) < 2)
		return ;
	last = ft_lstlast(*p_stack);
	before_last = ft_lst_before(*p_stack, last);
	before_last->next = NULL;
	last->next = *p_stack;
	*p_stack = last;
}

void	operate_rra(t_stack **p_a)
{
	reverse_rotate_stack(p_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	operate_rrb(t_stack **p_b)
{
	reverse_rotate_stack(p_b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	operate_rrr(t_stack **p_a, t_stack **p_b)
{
	reverse_rotate_stack(p_a);
	reverse_rotate_stack(p_b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
