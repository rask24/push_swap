/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nano_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/12 16:08:17 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_2(t_list *stack)
{
	int	first;
	int	second;

	first = ft_atoi(stack->content);
	second = ft_atoi(stack->next->content);
	if (first > second)
		ft_putendl_fd("sa", STDOUT_FILENO);
}

void	nano_sort(t_list *stack, int argc)
{
	int	num_of_element;

	num_of_element = argc - 1;
	if (num_of_element == 2)
		_handle_2(stack);
}
