/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:43:16 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/10 14:14:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*_find_opt_st_b(t_stack **p_b)
{
	t_stack	*st_b;

	st_b = *p_b;
	while (!get_content(st_b)->is_opt)
		st_b = st_b->next;
	return (st_b);
}

static void	_do_double_n_operation(t_stack **p_a, t_stack **p_b, int n,
		void (*operation)(t_stack **, t_stack **))
{
	while (n--)
		operation(p_a, p_b);
}

static void	_do_single_n_operation(t_stack **p_st, int n,
		void (*operation)(t_stack **))
{
	while (n--)
		operation(p_st);
}

static void	_do_opt_operation(t_stack **p_a, t_stack **p_b, t_stack *opt_st_b)
{
	int	sf_cost;
	int	sr_cost;
	int	if_cost;
	int	ir_cost;

	sf_cost = get_content(opt_st_b)->sf_cost;
	sr_cost = get_content(opt_st_b)->sr_cost;
	if_cost = get_content(opt_st_b)->if_cost;
	ir_cost = get_content(opt_st_b)->ir_cost;
	if (get_content(opt_st_b)->opt_method == FF)
	{
		_do_double_n_operation(p_a, p_b, ft_min(sf_cost, if_cost), operate_rr);
		if (sf_cost > if_cost)
			_do_single_n_operation(p_b, sf_cost - if_cost, operate_rb);
		else if (sf_cost < if_cost)
			_do_single_n_operation(p_a, if_cost - sf_cost, operate_ra);
	}
	else if (get_content(opt_st_b)->opt_method == FR)
	{
		_do_single_n_operation(p_b, sf_cost, operate_rb);
		_do_single_n_operation(p_a, -ir_cost, operate_rra);
	}
	else if (get_content(opt_st_b)->opt_method == RF)
	{
		_do_single_n_operation(p_b, -sr_cost, operate_rrb);
		_do_single_n_operation(p_a, if_cost, operate_ra);
	}
	else if (get_content(opt_st_b)->opt_method == RR)
	{
		_do_double_n_operation(p_a, p_b, ft_min(-sr_cost, -ir_cost),
			operate_rrr);
		if (-sr_cost > -ir_cost)
			_do_single_n_operation(p_b, -sr_cost + ir_cost, operate_rrb);
		else if (-sr_cost < -ir_cost)
			_do_single_n_operation(p_a, -ir_cost + sr_cost, operate_rra);
	}
	operate_pa(p_b, p_a);
}

void	greedy_operation(t_stack **p_a, t_stack **p_b)
{
	t_stack	*opt_st_b;

	opt_st_b = _find_opt_st_b(p_b);
	_do_opt_operation(p_a, p_b, opt_st_b);
}
