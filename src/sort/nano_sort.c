/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nano_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 15:34:25 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_2(t_list **stack)
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

static void	_handle_3(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	third = *(int *)(*stack)->next->next->content;
	if (first == 2 && second == 1 && third == 3)
		operate_sa(stack);
	else if (first == 3 && second == 2 && third == 1)
	{
		operate_sa(stack);
		operate_rra(stack);
	}
	else if (first == 3 && second == 1 && third == 2)
		operate_ra(stack);
	else if (first == 1 && second == 3 && third == 2)
	{
		operate_sa(stack);
		operate_ra(stack);
	}
	else if (first == 2 && second == 3 && third == 1)
		operate_rra(stack);
}

void	nano_sort(t_list **stack, int num_of_element)
{
	if (num_of_element == 2)
		_handle_2(stack);
	else if (num_of_element == 3)
		_handle_3(stack);
}
