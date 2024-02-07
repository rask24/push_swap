/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nano_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/07 15:04:35 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_2(t_stack **p_a)
{
	if (first_content(p_a) > second_content(p_a))
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

	first = first_content(p_a);
	second = second_content(p_a);
	third = third_content(p_a);
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
