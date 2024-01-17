/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/17 18:28:00 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_4(t_list **stack_a, t_list **stack_b)
{
	operate_pb(stack_a, stack_b);
	nano_sort(stack_a, 3);
	if (first_content(stack_b) == 1)
		operate_pa(stack_b, stack_a);
	else if (first_content(stack_b) == 2)
	{
		operate_pa(stack_b, stack_a);
		operate_sa(stack_a);
	}
	else if (first_content(stack_b) == 3)
	{
		operate_rra(stack_a);
		operate_pa(stack_b, stack_a);
		operate_ra(stack_a);
		operate_ra(stack_a);
	}
	else if (first_content(stack_b) == 4)
	{
		operate_pa(stack_b, stack_a);
		operate_ra(stack_a);
	}
}

static void	_handle_5(t_list **stack_a, t_list **stack_b)
{
	operate_pb(stack_a, stack_b);
	operate_pb(stack_a, stack_b);
	nano_sort(stack_a, 3);
	if (first_content(stack_b) < second_content(stack_b))
		operate_sb(stack_b);
	if (first_content(stack_b) == 5 && second_content(stack_b) == 4)
	{
		operate_pa(stack_b, stack_a);
		operate_pa(stack_b, stack_a);
		operate_ra(stack_a);
		operate_ra(stack_a);
		return ;
	}
	else if (first_content(stack_b) == 5)
	{
		operate_pa(stack_b, stack_a);
		operate_rra(stack_a);
	}
	else
	{
		while (first_content(stack_a) != first_content(stack_b) + 1)
			operate_ra(stack_a);
		operate_pa(stack_b, stack_a);
	}
	while (first_content(stack_a) != first_content(stack_b) + 1)
		operate_rra(stack_a);
	operate_pa(stack_b, stack_a);
	while (first_content(stack_a) != 1)
		operate_rra(stack_a);
}

void	micro_sort(t_list **stack_a, t_list **stack_b, int num_a)
{
	if (num_a == 4)
		_handle_4(stack_a, stack_b);
	else if (num_a == 5)
		_handle_5(stack_a, stack_b);
}
