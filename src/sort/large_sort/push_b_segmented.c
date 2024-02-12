/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_segmented.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:57:28 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/12 17:24:53 by reasuke          ###   ########.fr       */
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

static int	_calc_segment_id(int pushed, int n, int num_seg)
{
	int	seg_size;
	int	id;

	if (num_seg <= 0)
		return (-1);
	seg_size = n / num_seg;
	id = 0;
	while (id < num_seg)
	{
		if (id * seg_size <= pushed && pushed < (id + 1) * seg_size)
			return (id);
		id++;
	}
	if (pushed >= seg_size * num_seg)
		return (num_seg - 1);
	return (-1);
}

// ft_printf("ns: %d, index: %d, pushed: %d, n: %d\n", num_segment, index,
// 	pushed, n);
static bool	_should_push_b(int index, int pushed, int n, int num_seg)
{
	int	seg_size;
	int	cur_id;
	int	inf;
	int	sup;

	seg_size = n / num_seg;
	cur_id = _calc_segment_id(pushed, n, num_seg);
	inf = seg_size * cur_id;
	sup = seg_size * (cur_id + 1);
	if (cur_id == num_seg - 1)
		sup = n;
	return (inf < index && index <= sup);
}

void	push_b_segmented(t_stack **p_a, t_stack **p_b, int n)
{
	int	pushed;
	int	num_seg;

	pushed = 0;
	num_seg = 5;
	while (pushed < n)
	{
		if (_should_push_b(get_content(*p_a)->index, pushed, n, num_seg))
		{
			operate_pb(p_a, p_b);
			if (_calc_segment_id(pushed, n, num_seg) % 2 == 1)
				operate_rb(p_b);
			pushed++;
		}
		else
			operate_ra(p_a);
	}
}
