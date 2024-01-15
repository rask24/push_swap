/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 16:52:45 by reasuke          ###   ########.fr       */
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
	{
		push_stack(stack_b, stack_a);
		ft_putendl_fd("pa", STDOUT_FILENO);
	}
	if (tmp == 2)
	{
		push_stack(stack_b, stack_a);
		ft_putendl_fd("pa", STDOUT_FILENO);
		operate_sa(stack_a);
	}
	else if (tmp == 3)
	{
		operate_rra(stack_a);
		push_stack(stack_b, stack_a);
		ft_putendl_fd("pa", STDOUT_FILENO);
		operate_ra(stack_a);
		operate_ra(stack_a);
	}
	else if (tmp == 4)
	{
		push_stack(stack_b, stack_a);
		ft_putendl_fd("pa", STDOUT_FILENO);
		operate_ra(stack_a);
	}
}
