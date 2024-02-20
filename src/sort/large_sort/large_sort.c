/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:55:10 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:17:35 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"
#include "sort.h"
#include "stack_operations.h"

static int	_calc_number_of_segments(int size_a)
{
	int	step;

	if (size_a < 100)
		return (1);
	step = (size_a - 100) / 150;
	return (2 * step + 3);
}

static void	_sort_stack_a(t_stack **p_a, int num_a)
{
	if (get_content(*p_a)->index > num_a / 2)
	{
		while (!is_sorted_stack(*p_a))
			operate_ra(p_a);
	}
	else
	{
		while (!is_sorted_stack(*p_a))
			operate_rra(p_a);
	}
}

void	large_sort(t_stack **p_a, t_stack **p_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*p_a);
	size_b = size_a - 3;
	push_b_segmented(p_a, p_b, size_b, _calc_number_of_segments(size_a));
	nano_sort(p_a);
	while (size_b--)
	{
		set_cost(p_a, p_b);
		set_min_cost_opt_method(p_b);
		set_is_target(p_b);
		greedy_operation(p_a, p_b);
	}
	_sort_stack_a(p_a, size_a);
}
