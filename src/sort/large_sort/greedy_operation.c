/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:43:16 by reasuke           #+#    #+#             */
/*   Updated: 2024/04/20 16:01:25 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_sort.h"
#include "stack_operations.h"

static t_stack	*_find_opt_st_b(t_stack **p_b)
{
	t_stack	*st_b;

	st_b = *p_b;
	while (!get_content(st_b)->is_target)
		st_b = st_b->next;
	return (st_b);
}

static void	_do_alined_operation(t_stack **p_a, t_stack **p_b,
		t_stack *opt_st_b)
{
	int	n_a;
	int	n_b;

	if (get_content(opt_st_b)->opt_method == RA_RB)
	{
		n_b = ft_abs(get_content(opt_st_b)->rb_cost);
		n_a = ft_abs(get_content(opt_st_b)->ra_cost);
		repeat_dual_stack_operations(p_a, p_b, ft_min(n_b, n_a), operate_rr);
		if (n_b > n_a)
			repeat_stack_operations(p_b, n_b - n_a, operate_rb);
		else if (n_b < n_a)
			repeat_stack_operations(p_a, n_a - n_b, operate_ra);
	}
	if (get_content(opt_st_b)->opt_method == RRA_RRB)
	{
		n_b = ft_abs(get_content(opt_st_b)->rrb_cost);
		n_a = ft_abs(get_content(opt_st_b)->rra_cost);
		repeat_dual_stack_operations(p_a, p_b, ft_min(n_b, n_a), operate_rrr);
		if (n_b > n_a)
			repeat_stack_operations(p_b, n_b - n_a, operate_rrb);
		else if (n_b < n_a)
			repeat_stack_operations(p_a, n_a - n_b, operate_rra);
	}
}

static void	_do_mixed_operation(t_stack **p_a, t_stack **p_b, t_stack *opt_st_b)
{
	int	n_a;
	int	n_b;

	if (get_content(opt_st_b)->opt_method == RRA_RB)
	{
		n_a = ft_abs(get_content(opt_st_b)->rra_cost);
		n_b = ft_abs(get_content(opt_st_b)->rb_cost);
		repeat_stack_operations(p_b, n_b, operate_rb);
		repeat_stack_operations(p_a, n_a, operate_rra);
	}
	if (get_content(opt_st_b)->opt_method == RA_RRB)
	{
		n_a = ft_abs(get_content(opt_st_b)->ra_cost);
		n_b = ft_abs(get_content(opt_st_b)->rrb_cost);
		repeat_stack_operations(p_b, n_b, operate_rrb);
		repeat_stack_operations(p_a, n_a, operate_ra);
	}
}

static void	_do_opt_operation(t_stack **p_a, t_stack **p_b, t_stack *opt_st_b)
{
	t_method	opt_method;

	opt_method = get_content(opt_st_b)->opt_method;
	if (opt_method == RA_RB || opt_method == RRA_RRB)
		_do_alined_operation(p_a, p_b, opt_st_b);
	else if (opt_method == RRA_RB || opt_method == RA_RRB)
		_do_mixed_operation(p_a, p_b, opt_st_b);
	operate_pa(p_b, p_a);
}

void	greedy_operation(t_stack **p_a, t_stack **p_b)
{
	t_stack	*opt_st_b;

	opt_st_b = _find_opt_st_b(p_b);
	_do_opt_operation(p_a, p_b, opt_st_b);
}
