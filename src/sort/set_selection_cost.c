/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_selection_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:17 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/07 16:49:26 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_selection_cost(t_stack **p_b)
{
	t_stack	*st;
	int		size_b;
	int		i;

	st = *p_b;
	size_b = stack_size(*p_b);
	i = 0;
	while (i < size_b)
	{
		((t_content *)st->content)->sf_cost = i;
		((t_content *)st->content)->sr_cost = -((size_b - i) % size_b);
		st = st->next;
		i++;
	}
}
