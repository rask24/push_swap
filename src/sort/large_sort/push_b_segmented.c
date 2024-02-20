/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_segmented.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:57:28 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:17:46 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"
#include "stack_operations.h"

static int	_calc_segment_id(int target, int n, int segs)
{
	int	seg_size;
	int	id;

	if (segs <= 0)
		return (-1);
	seg_size = n / segs;
	id = 0;
	while (id < segs)
	{
		if (id * seg_size <= target && target < (id + 1) * seg_size)
			return (id);
		id++;
	}
	if (target >= seg_size * segs)
		return (segs - 1);
	return (-1);
}

static bool	_should_push_b(int index, int pushed, int n, int segs)
{
	int	seg_size;
	int	cur_id;
	int	inf;
	int	sup;

	seg_size = n / segs;
	cur_id = _calc_segment_id(pushed, n, segs);
	if (cur_id % 2 == 0)
	{
		inf = seg_size * cur_id;
		sup = seg_size * (cur_id + 2);
	}
	else
	{
		inf = seg_size * (cur_id - 1);
		sup = seg_size * (cur_id + 1);
	}
	if (cur_id == segs - 1)
		return (inf <= index);
	return (inf <= index && index < sup);
}

void	push_b_segmented(t_stack **p_a, t_stack **p_b, int n, int segs)
{
	int	pushed;
	int	index;
	int	segment;

	pushed = 0;
	while (pushed < n)
	{
		index = get_content(*p_a)->index;
		if (_should_push_b(index, pushed, n, segs))
		{
			segment = _calc_segment_id(index, n, segs);
			get_content(*p_a)->segment = segment;
			operate_pb(p_a, p_b);
			if (segment % 2 == 1)
				operate_rb(p_b);
			pushed++;
		}
		else
			operate_ra(p_a);
	}
}
