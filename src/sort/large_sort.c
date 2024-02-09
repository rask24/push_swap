/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:55:10 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/09 23:08:48 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_init_stack(t_stack **p_a, t_stack **p_b, int num_a)
{
	int	i;

	i = 0;
	while (i < num_a - 3)
	{
		operate_pb(p_a, p_b);
		i++;
	}
}

void	large_sort(t_stack **p_a, t_stack **p_b, int num_a)
{
	_init_stack(p_a, p_b, num_a);
	nano_sort(p_a, 3);
	set_cost(p_a, p_b);
	set_opt(p_b);
}
