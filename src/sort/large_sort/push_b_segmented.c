/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_segmented.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:57:28 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/12 23:28:29 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"
#include "push_swap.h"
#include "stack_operations.h"

// 1 ~ 100
// segment1: 1 ~ 20
// segment1: 21 ~ 40
// segment1: 41 ~ 60
// segment1: 61 ~ 80
// segment1: 81 ~ 100

// 123: 24
// [0, 24) -> [0, seg_size)
// [24, 48) -> [seg_size, seg_size * 2)
// [48, 72) -> [seg_size * 2, seg_size * 3)
// [72, 96) -> [seg_size * 3, seg_size * 4)
// [96, 123) -> [seg_size * 4, N)

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

// ft_printf("ns: %d, index: %d, pushed: %d, n: %d\n", num_segment, index,
// 	pushed, n);
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
		return (inf < index && index <= n);
	return (inf < index && index <= sup);
}

void	push_b_segmented(t_stack **p_a, t_stack **p_b, int n, int segs)
{
	int	pushed;
	int	index;

	pushed = 0;
	while (pushed < n)
	{
		index = get_content(*p_a)->index;
		if (_should_push_b(index, pushed, n, segs))
		{
			operate_pb(p_a, p_b);
			if (_calc_segment_id(index - 1, n, segs) % 2 == 1)
				operate_rb(p_b);
			pushed++;
		}
		else
			operate_ra(p_a);
	}
}
