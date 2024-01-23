/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:55:10 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/23 15:58:27 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// naive implement: insertion sort
// find smallest number of a
// rotate
// push to b
// push to a

static void	push_in_order(t_list **p_a, t_list **p_b, int num_a)
{
	int	i;

	i = 1;
	while (i <= num_a)
	{
		if (first_content(p_a) == i)
		{
			operate_pb(p_a, p_b);
			i++;
		}
		else
			operate_ra(p_a);
	}
}

static void	push_revert(t_list **p_a, t_list **p_b, int num_a)
{
	int	i;

	i = 0;
	while (i < num_a)
	{
		operate_pa(p_b, p_a);
		i++;
	}
}

void	large_sort(t_list **p_a, t_list **p_b, int num_a)
{
	push_in_order(p_a, p_b, num_a);
	push_revert(p_a, p_b, num_a);
}
