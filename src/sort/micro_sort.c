/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/17 17:37:32 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_first(t_list **stack)
{
	return (*(int *)(*stack)->content);
}

static int	_second(t_list **stack)
{
	return (*(int *)(*stack)->next->content);
}

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

static void	_handle_5(t_list **stack_a, t_list **stack_b)
{
	operate_pb(stack_a, stack_b);
	operate_pb(stack_a, stack_b);
	nano_sort(stack_a, 3);
	if (_first(stack_b) < _second(stack_b))
		operate_sb(stack_b);
	if (_first(stack_b) == 5)
	{
		operate_pa(stack_b, stack_a);
		operate_rra(stack_a);
	}
	else
	{
		while (_first(stack_a) != _first(stack_b) + 1)
			operate_ra(stack_a);
		operate_pa(stack_b, stack_a);
	}
	while (_first(stack_a) != _first(stack_b) + 1)
		operate_rra(stack_a);
	operate_pa(stack_b, stack_a);
	while (_first(stack_a) != 1)
		operate_rra(stack_a);
}

void	micro_sort(t_list **stack_a, t_list **stack_b, int num_a)
{
	if (num_a == 4)
		_handle_4(stack_a, stack_b);
	else if (num_a == 5)
		_handle_5(stack_a, stack_b);
}
