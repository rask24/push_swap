/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:23:28 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/11 12:53:55 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"
#include "push_swap.h"

static int	_calc_cost(t_stack *st_b, t_method method)
{
	int	sf_cost;
	int	sr_cost;
	int	if_cost;
	int	ir_cost;

	sf_cost = get_content(st_b)->sf_cost;
	sr_cost = get_content(st_b)->sr_cost;
	if_cost = get_content(st_b)->if_cost;
	ir_cost = get_content(st_b)->ir_cost;
	if (method == FF)
		return (ft_max(sf_cost, if_cost));
	else if (method == FR)
		return (sf_cost - ir_cost);
	else if (method == RF)
		return (if_cost - sr_cost);
	else if (method == RR)
		return (ft_max(-sr_cost, -ir_cost));
	return (-1);
}

static void	_set_opt_method(t_stack *st_b, int *cost)
{
	if (ft_chmin(cost, _calc_cost(st_b, FF)))
		get_content(st_b)->opt_method = FF;
	if (ft_chmin(cost, _calc_cost(st_b, FR)))
		get_content(st_b)->opt_method = FR;
	if (ft_chmin(cost, _calc_cost(st_b, RF)))
		get_content(st_b)->opt_method = RF;
	if (ft_chmin(cost, _calc_cost(st_b, RR)))
		get_content(st_b)->opt_method = RR;
}

static void	_set_min_cost_opt_method(t_stack **p_b)
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

static void	_set_is_opt(t_stack **p_b)
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

void	set_opt(t_stack **p_b)
{
	_set_min_cost_opt_method(p_b);
	_set_is_opt(p_b);
}
