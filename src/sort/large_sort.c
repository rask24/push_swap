/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:55:10 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/22 17:02:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// naive implement: insertion sort
// find smallest number of a
// rotate
// push to stack_b
// push to stack_a

static void	push_in_order(t_list **stack_a, t_list **stack_b, int num_a)
{
	int	i;

	i = 1;
	while (i <= num_a)
	{
		if (first_content(stack_a) == i)
		{
			operate_pb(stack_a, stack_b);
			i++;
		}
		else
			operate_ra(stack_a);
	}
}

static void	push_revert(t_list **stack_a, t_list **stack_b, int num_a)
{
	int	i;

	i = 0;
	while (i < num_a)
	{
		operate_pa(stack_b, stack_a);
		i++;
	}
}

void	large_sort(t_list **stack_a, t_list **stack_b, int num_a)
{
	push_in_order(stack_a, stack_b, num_a);
	push_revert(stack_a, stack_b, num_a);
}
