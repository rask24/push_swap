/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:35 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/10 21:36:16 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **p_a, t_stack **p_b)
{
	int	size_a;

	if (is_sorted_stack(*p_a))
		return ;
	size_a = stack_size(*p_a);
	if (size_a <= 3)
		nano_sort(p_a);
	else if (size_a <= 5)
		micro_sort(p_a, p_b);
	else
		large_sort(p_a, p_b);
}
