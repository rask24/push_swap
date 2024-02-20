/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_is_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:44:38 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:17:53 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"

static int	_calc_max_segment(t_stack *st_b)
{
	int	max_seg;

	max_seg = INT_MIN;
	while (st_b)
	{
		ft_chmax(&max_seg, get_content(st_b)->segment);
		st_b = st_b->next;
	}
	return (max_seg);
}

static int	_calc_target_index(t_stack *st_b, int max_seg)
{
	int	target_index;
	int	cost;
	int	i;

	target_index = -1;
	cost = INT_MAX;
	i = 0;
	while (st_b)
	{
		if (get_content(st_b)->segment == max_seg && ft_chmin(&cost,
				get_content(st_b)->min_cost))
			target_index = i;
		i++;
		st_b = st_b->next;
	}
	return (target_index);
}

void	set_is_target(t_stack **p_b)
{
	int		i;
	t_stack	*st_b;
	int		max_seg;
	int		target_index;

	st_b = *p_b;
	max_seg = _calc_max_segment(st_b);
	target_index = _calc_target_index(st_b, max_seg);
	i = 0;
	while (i++ < target_index)
		st_b = st_b->next;
	get_content(st_b)->is_target = true;
}
