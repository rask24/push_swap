/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nano_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 12:58:12 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_handle_2(t_list *stack)
{
	int	first;
	int	second;

	first = *(int *)stack->content;
	second = *(int *)stack->next->content;
	if (first > second)
		ft_putendl_fd("sa", STDOUT_FILENO);
}

static void	_handel_3(t_list *stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)stack->content;
	second = *(int *)stack->next->content;
	third = *(int *)stack->next->next->content;
	if (first == 2 && second == 1 && third == 3)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (first == 3 && second == 2 && third == 1)
	{
		ft_putendl_fd("sa", STDOUT_FILENO);
		ft_putendl_fd("rra", STDOUT_FILENO);
	}
	else if (first == 3 && second == 1 && third == 2)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (first == 1 && second == 3 && third == 2)
	{
		ft_putendl_fd("sa", STDOUT_FILENO);
		ft_putendl_fd("ra", STDOUT_FILENO);
	}
	else if (first == 2 && second == 3 && third == 1)
		ft_putendl_fd("rra", STDOUT_FILENO);
}

void	nano_sort(t_list *stack, int argc)
{
	int	num_of_element;

	num_of_element = argc - 1;
	if (num_of_element == 2)
		_handle_2(stack);
	else if (num_of_element == 3)
		_handel_3(stack);
}
