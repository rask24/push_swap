/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 16:59:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	micro_sort(t_list **stack_a, t_list **stack_b)
{
	int	tmp;

	push_stack(stack_a, stack_b);
	ft_putendl_fd("pb", STDOUT_FILENO);
	tmp = *(int *)(*stack_b)->content;
	nano_sort(stack_a, 3);
	if (tmp == 1)
		operate_pa(stack_b, stack_a);
	if (tmp == 2)
	{
		operate_pa(stack_b, stack_a);
		operate_sa(stack_a);
	}
	else if (tmp == 3)
	{
		operate_rra(stack_a);
		operate_pa(stack_b, stack_a);
		operate_ra(stack_a);
		operate_ra(stack_a);
	}
	else if (tmp == 4)
	{
		operate_pa(stack_b, stack_a);
		operate_ra(stack_a);
	}
}
