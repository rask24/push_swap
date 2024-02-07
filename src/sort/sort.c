/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:35 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/07 15:04:45 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **p_a, t_stack **p_b, int num_a)
{
	if (num_a <= 3)
		nano_sort(p_a, num_a);
	else if (num_a <= 5)
		micro_sort(p_a, p_b, num_a);
}
