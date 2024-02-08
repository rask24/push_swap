/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_insertion_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:32:05 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/08 10:09:34 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_set_insertion_forward_cost(t_stack **p_a, t_stack *st_b)
{
	t_stack	*st_a;
	int		size_a;
	int		i;
	int		threshold;
	int		max_a;
	int		max_index;
	int		min;

	st_a = *p_a;
	size_a = stack_size(*p_a);
	i = 0;
	threshold = INT_MAX;
	min = INT_MAX;
	max_a = INT_MIN;
	while (i < size_a)
	{
		if (get_content(st_a)->index > get_content(st_b)->index
			&& ft_chmin(&min, get_content(st_a)->index))
			threshold = i;
		if (ft_chmax(&max_a, get_content(st_a)->index))
			max_index = i;
		st_a = st_a->next;
		i++;
	}
	if (threshold == INT_MAX)
		threshold = (max_index + 1) % size_a;
	get_content(st_b)->if_cost = threshold % size_a;
}

static void	_set_insertion_reverse_cost(t_stack **p_a, t_stack *st_b)
{
	t_stack	*st_a;
	int		size_a;
	int		i;
	int		threshold;
	int		max_a;
	int		max_index;
	int		min;

	st_a = *p_a;
	size_a = stack_size(*p_a);
	i = 0;
	threshold = INT_MAX;
	min = INT_MAX;
	max_a = INT_MIN;
	while (i < size_a)
	{
		if (get_content(st_a)->index > get_content(st_b)->index
			&& ft_chmin(&min, get_content(st_a)->index))
			threshold = i;
		if (ft_chmax(&max_a, get_content(st_a)->index))
			max_index = i;
		st_a = st_a->next;
		i++;
	}
	if (threshold == INT_MAX)
		threshold = (max_index + 1) % size_a;
	get_content(st_b)->ir_cost = -((size_a - threshold) % size_a);
}

void	set_insertion_cost(t_stack **p_a, t_stack **p_b)
{
	t_stack	*st_b;
	int		size_b;
	int		i;

	st_b = *p_b;
	size_b = stack_size(*p_b);
	i = 0;
	while (i < size_b)
	{
		_set_insertion_forward_cost(p_a, st_b);
		_set_insertion_reverse_cost(p_a, st_b);
		st_b = st_b->next;
		i++;
	}
}
