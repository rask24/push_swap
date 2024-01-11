/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:04:40 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/11 19:36:37 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*generate_stack(int argc, char **argv)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&stack, ft_lstnew(argv[i]));
		i++;
	}
	return (stack);
}
