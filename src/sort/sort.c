/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:35 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/17 16:08:05 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b, int num_a)
{
	if (num_a <= 3)
		nano_sort(stack_a, num_a);
	else if (num_a <= 5)
		micro_sort(stack_a, stack_b, num_a);
}
