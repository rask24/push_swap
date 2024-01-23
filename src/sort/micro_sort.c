/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/23 15:29:19 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_4(t_stack **p_a, t_stack **p_b)
{
	operate_pb(p_a, p_b);
	nano_sort(p_a, 3);
	if (first_content(p_b) == 1)
		operate_pa(p_b, p_a);
	else if (first_content(p_b) == 2)
	{
		operate_pa(p_b, p_a);
		operate_sa(p_a);
	}
	else if (first_content(p_b) == 3)
	{
		operate_rra(p_a);
		operate_pa(p_b, p_a);
		operate_ra(p_a);
		operate_ra(p_a);
	}
	else if (first_content(p_b) == 4)
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
	if (first_content(p_b) == 5)
	{
		operate_pa(p_b, p_a);
		operate_rra(p_a);
	}
	else
	{
		while (first_content(p_a) != first_content(p_b) + 1)
			operate_ra(p_a);
		operate_pa(p_b, p_a);
	}
	while (first_content(p_a) != first_content(p_b) + 1)
		operate_rra(p_a);
	operate_pa(p_b, p_a);
	while (first_content(p_a) != 1)
		operate_rra(p_a);
}

static void	_handle_5(t_stack **p_a, t_stack **p_b)
{
	operate_pb(p_a, p_b);
	operate_pb(p_a, p_b);
	nano_sort(p_a, 3);
	if (first_content(p_b) < second_content(p_b))
		operate_sb(p_b);
	if (first_content(p_b) == 5 && second_content(p_b) == 4)
		_edge_flow_5(p_a, p_b);
	else
		_normal_flow_5(p_a, p_b);
}

void	micro_sort(t_stack **p_a, t_stack **p_b, int num_a)
{
	if (num_a == 4)
		_handle_4(p_a, p_b);
	else if (num_a == 5)
		_handle_5(p_a, p_b);
}
