/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_cost_opt_method.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:23:28 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/14 15:44:15 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"
#include "push_swap.h"

static int	_calc_cost(t_stack *st_b, t_method method)
{
	int	rb_cost;
	int	rrb_cost;
	int	ra_cost;
	int	rra_cost;

	rb_cost = get_content(st_b)->rb_cost;
	rrb_cost = get_content(st_b)->rrb_cost;
	ra_cost = get_content(st_b)->ra_cost;
	rra_cost = get_content(st_b)->rra_cost;
	if (method == RA_RB)
		return (ft_max(rb_cost, ra_cost));
	else if (method == RRA_RB)
		return (rb_cost - rra_cost);
	else if (method == RA_RRB)
		return (ra_cost - rrb_cost);
	else if (method == RRA_RRB)
		return (ft_max(-rrb_cost, -rra_cost));
	return (-1);
}

static void	_set_opt_method(t_stack *st_b, int *cost)
{
	if (ft_chmin(cost, _calc_cost(st_b, RA_RB)))
		get_content(st_b)->opt_method = RA_RB;
	if (ft_chmin(cost, _calc_cost(st_b, RRA_RB)))
		get_content(st_b)->opt_method = RRA_RB;
	if (ft_chmin(cost, _calc_cost(st_b, RA_RRB)))
		get_content(st_b)->opt_method = RA_RRB;
	if (ft_chmin(cost, _calc_cost(st_b, RRA_RRB)))
		get_content(st_b)->opt_method = RRA_RRB;
}

void	set_min_cost_opt_method(t_stack **p_b)
{
	int		i;
	int		size_b;
	int		cost;
	t_stack	*st_b;

	i = 0;
	size_b = stack_size(*p_b);
	st_b = *p_b;
	while (i < size_b)
	{
		cost = INT_MAX;
		_set_opt_method(st_b, &cost);
		get_content(st_b)->min_cost = cost;
		st_b = st_b->next;
		i++;
	}
}
