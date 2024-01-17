/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/17 16:07:10 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_4(t_list **stack_a, t_list **stack_b)
{
	int	first;

	operate_pb(stack_a, stack_b);
	nano_sort(stack_a, 3);
	first = *(int *)(*stack_b)->content;
	if (first == 1)
		operate_pa(stack_b, stack_a);
	if (first == 2)
	{
		operate_pa(stack_b, stack_a);
		operate_sa(stack_a);
	}
	else if (first == 3)
	{
		operate_rra(stack_a);
		operate_pa(stack_b, stack_a);
		operate_ra(stack_a);
		operate_ra(stack_a);
	}
	else if (first == 4)
	{
		operate_pa(stack_b, stack_a);
		operate_ra(stack_a);
	}
}

void	micro_sort(t_list **stack_a, t_list **stack_b, int num_a)
{
	if (num_a == 4)
		_handle_4(stack_a, stack_b);
}
