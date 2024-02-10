/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:55:10 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/10 19:16:52 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_init_stack(t_stack **p_a, t_stack **p_b, int num_a)
{
	int	i;

	i = 0;
	while (i < num_a - 3)
	{
		operate_pb(p_a, p_b);
		i++;
	}
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

void	large_sort(t_stack **p_a, t_stack **p_b, int num_a)
{
	int	i;

	_init_stack(p_a, p_b, num_a);
	nano_sort(p_a, 3);
	i = 0;
	while (i < num_a - 3)
	{
		set_cost(p_a, p_b);
		set_opt(p_b);
		greedy_operation(p_a, p_b);
		i++;
	}
	_sort_stack_a(p_a, num_a);
}
