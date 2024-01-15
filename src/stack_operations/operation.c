/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:32:19 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 15:33:01 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_sa(t_list **stack_a)
{
	swap_stack(stack_a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	operate_ra(t_list **stack_a)
{
	rotate_stack(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	operate_rra(t_list **stack_a)
{
	swap_stack(stack_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}
