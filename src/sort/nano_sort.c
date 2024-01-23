/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nano_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/23 15:11:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_2(t_stack **stack)
{
	int	first;
	int	second;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	if (first > second)
	{
		swap_stack(stack);
		ft_putendl_fd("sa", STDOUT_FILENO);
	}
}

static void	_handle_3(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	third = *(int *)(*stack)->next->next->content;
	if (second < first && first < third)
		operate_sa(stack);
	else if (third < second && second < first)
	{
		operate_sa(stack);
		operate_rra(stack);
	}
	else if (second < third && third < first)
		operate_ra(stack);
	else if (first < third && third < second)
	{
		operate_sa(stack);
		operate_ra(stack);
	}
	else if (third < first && first < second)
		operate_rra(stack);
}

void	nano_sort(t_stack **stack, int num_a)
{
	if (num_a == 2)
		_handle_2(stack);
	else if (num_a == 3)
		_handle_3(stack);
}
