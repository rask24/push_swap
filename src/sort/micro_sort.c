/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:18:10 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack_operations.h"

static void	_handle_4(t_stack **p_a, t_stack **p_b)
{
	operate_pb(p_a, p_b);
	nano_sort(p_a);
	if (get_first_index(p_b) == 0)
		operate_pa(p_b, p_a);
	else if (get_first_index(p_b) == 1)
	{
		operate_pa(p_b, p_a);
		operate_sa(p_a);
	}
	else if (get_first_index(p_b) == 2)
	{
		operate_rra(p_a);
		operate_pa(p_b, p_a);
		operate_ra(p_a);
		operate_ra(p_a);
	}
	else if (get_first_index(p_b) == 3)
	{
		operate_pa(p_b, p_a);
		operate_ra(p_a);
	}
}

static void	_edge_flow_5(t_stack **p_a, t_stack **p_b)
{
	operate_pa(p_b, p_a);
	operate_pa(p_b, p_a);
	operate_ra(p_a);
	operate_ra(p_a);
}

static void	_normal_flow_5(t_stack **p_a, t_stack **p_b)
{
	if (get_first_index(p_b) == 4)
	{
		operate_pa(p_b, p_a);
		operate_rra(p_a);
	}
	else
	{
		while (get_first_index(p_a) != get_first_index(p_b) + 1)
			operate_ra(p_a);
		operate_pa(p_b, p_a);
	}
	while (get_first_index(p_a) != get_first_index(p_b) + 1)
		operate_rra(p_a);
	operate_pa(p_b, p_a);
	while (get_first_index(p_a) != 0)
		operate_rra(p_a);
}

static void	_handle_5(t_stack **p_a, t_stack **p_b)
{
	operate_pb(p_a, p_b);
	operate_pb(p_a, p_b);
	nano_sort(p_a);
	if (get_first_index(p_b) < get_second_index(p_b))
		operate_sb(p_b);
	if (get_first_index(p_b) == 4 && get_second_index(p_b) == 3)
		_edge_flow_5(p_a, p_b);
	else
		_normal_flow_5(p_a, p_b);
}

void	micro_sort(t_stack **p_a, t_stack **p_b)
{
	int	size_a;

	size_a = stack_size(*p_a);
	if (size_a == 4)
		_handle_4(p_a, p_b);
	else if (size_a == 5)
		_handle_5(p_a, p_b);
}
