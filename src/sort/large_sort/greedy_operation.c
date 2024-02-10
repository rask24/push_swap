/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:43:16 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/10 20:34:46 by reasuke          ###   ########.fr       */
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

static void	_do_alined_operation(t_stack **p_a, t_stack **p_b,
		t_stack *opt_st_b)
{
	int	sf_abs;
	int	sr_abs;
	int	if_abs;
	int	ir_abs;

	sf_abs = ft_abs(get_content(opt_st_b)->sf_cost);
	sr_abs = ft_abs(get_content(opt_st_b)->sr_cost);
	if_abs = ft_abs(get_content(opt_st_b)->if_cost);
	ir_abs = ft_abs(get_content(opt_st_b)->ir_cost);
	if (get_content(opt_st_b)->opt_method == FF)
	{
		do_double_n_operations(p_a, p_b, ft_min(sf_abs, if_abs), operate_rr);
		if (sf_abs > if_abs)
			do_single_n_operations(p_b, sf_abs - if_abs, operate_rb);
		else if (sf_abs < if_abs)
			do_single_n_operations(p_a, if_abs - sf_abs, operate_ra);
	}
	if (get_content(opt_st_b)->opt_method == RR)
	{
		do_double_n_operations(p_a, p_b, ft_min(sr_abs, ir_abs), operate_rrr);
		if (sr_abs > ir_abs)
			do_single_n_operations(p_b, sr_abs - ir_abs, operate_rrb);
		else if (sr_abs < ir_abs)
			do_single_n_operations(p_a, ir_abs - sr_abs, operate_rra);
	}
}

static void	_do_mixed_operation(t_stack **p_a, t_stack **p_b, t_stack *opt_st_b)
{
	int	sf_abs;
	int	sr_abs;
	int	if_abs;
	int	ir_abs;

	sf_abs = ft_abs(get_content(opt_st_b)->sf_cost);
	sr_abs = ft_abs(get_content(opt_st_b)->sr_cost);
	if_abs = ft_abs(get_content(opt_st_b)->if_cost);
	ir_abs = ft_abs(get_content(opt_st_b)->ir_cost);
	if (get_content(opt_st_b)->opt_method == FR)
	{
		do_single_n_operations(p_b, sf_abs, operate_rb);
		do_single_n_operations(p_a, ir_abs, operate_rra);
	}
	if (get_content(opt_st_b)->opt_method == RF)
	{
		do_single_n_operations(p_b, sr_abs, operate_rrb);
		do_single_n_operations(p_a, if_abs, operate_ra);
	}
}

static void	_do_opt_operation(t_stack **p_a, t_stack **p_b, t_stack *opt_st_b)
{
	t_method	opt_method;

	opt_method = get_content(opt_st_b)->opt_method;
	if (opt_method == FF || opt_method == RR)
		_do_alined_operation(p_a, p_b, opt_st_b);
	else if (opt_method == FR || opt_method == RF)
		_do_mixed_operation(p_a, p_b, opt_st_b);
	operate_pa(p_b, p_a);
}

void	greedy_operation(t_stack **p_a, t_stack **p_b)
{
	t_stack	*opt_st_b;

	opt_st_b = _find_opt_st_b(p_b);
	_do_opt_operation(p_a, p_b, opt_st_b);
}