/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_is_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:44:38 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/14 14:45:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"
#include "push_swap.h"

void	set_is_opt(t_stack **p_b)
{
	int		i;
	t_stack	*st_b;
	int		size_b;
	int		opt_cost;
	int		min_index;

	size_b = stack_size(*p_b);
	i = 0;
	st_b = *p_b;
	opt_cost = INT_MAX;
	min_index = -1;
	while (i < size_b)
	{
		if (ft_chmin(&opt_cost, get_content(st_b)->min_cost))
			min_index = i;
		st_b = st_b->next;
		i++;
	}
	i = 0;
	st_b = *p_b;
	while (i++ < min_index)
		st_b = st_b->next;
	get_content(st_b)->is_opt = true;
}
