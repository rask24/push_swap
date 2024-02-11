/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:17:33 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/11 12:53:50 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"
#include "push_swap.h"

static int	_calc_insertion_threshold(t_stack **p_a, t_stack *st_b)
{
	t_stack	*st_a;
	int		size_a;
	int		i;
	int		threshold;
	int		min;

	st_a = *p_a;
	size_a = stack_size(*p_a);
	i = 0;
	threshold = INT_MAX;
	min = INT_MAX;
	while (i < size_a)
	{
		if (get_content(st_a)->index > get_content(st_b)->index
			&& ft_chmin(&min, get_content(st_a)->index))
			threshold = i;
		st_a = st_a->next;
		i++;
	}
	return (threshold);
}

static int	_calc_max_index(t_stack **p_a)
{
	t_stack	*st_a;
	int		size_a;
	int		i;
	int		max_a;
	int		max_index;

	st_a = *p_a;
	size_a = stack_size(*p_a);
	i = 0;
	max_a = INT_MIN;
	max_index = -1;
	while (i < size_a)
	{
		if (ft_chmax(&max_a, get_content(st_a)->index))
			max_index = i;
		st_a = st_a->next;
		i++;
	}
	return (max_index);
}

static void	_set_insertion_cost(t_stack **p_a, t_stack *st_b)
{
	int	max_index;
	int	size_a;
	int	threshold;

	size_a = stack_size(*p_a);
	threshold = _calc_insertion_threshold(p_a, st_b);
	max_index = _calc_max_index(p_a);
	if (threshold == INT_MAX)
		threshold = (max_index + 1) % size_a;
	get_content(st_b)->if_cost = threshold % size_a;
	get_content(st_b)->ir_cost = -((size_a - threshold) % size_a);
}

static void	_set_selection_cost(t_stack *st_b, int i, int size_b)
{
	get_content(st_b)->sf_cost = i;
	get_content(st_b)->sr_cost = -((size_b - i) % size_b);
}

void	set_cost(t_stack **p_a, t_stack **p_b)
{
	t_stack	*st_b;
	int		size_b;
	int		i;

	st_b = *p_b;
	size_b = stack_size(*p_b);
	i = 0;
	while (i < size_b)
	{
		_set_selection_cost(st_b, i, size_b);
		_set_insertion_cost(p_a, st_b);
		st_b = st_b->next;
		i++;
	}
}
