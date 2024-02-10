/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nano_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/10 20:56:41 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_2(t_stack **p_a)
{
	if (get_first_index(p_a) > get_second_index(p_a))
	{
		swap_stack(p_a);
		ft_putendl_fd("sa", STDOUT_FILENO);
	}
}

static void	_handle_3(t_stack **p_a)
{
	int	first;
	int	second;
	int	third;

	first = get_first_index(p_a);
	second = get_second_index(p_a);
	third = get_third_index(p_a);
	if (second < first && first < third)
		operate_sa(p_a);
	else if (third < second && second < first)
	{
		operate_sa(p_a);
		operate_rra(p_a);
	}
	else if (second < third && third < first)
		operate_ra(p_a);
	else if (first < third && third < second)
	{
		operate_sa(p_a);
		operate_ra(p_a);
	}
	else if (third < first && first < second)
		operate_rra(p_a);
}

void	nano_sort(t_stack **p_a, int num_a)
{
	if (num_a == 2)
		_handle_2(p_a);
	else if (num_a == 3)
		_handle_3(p_a);
}
