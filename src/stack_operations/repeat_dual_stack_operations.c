/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_dual_stack_operations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:22:50 by reasuke           #+#    #+#             */
/*   Updated: 2024/04/20 15:40:46 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	repeat_dual_stack_operations(t_stack **p_a, t_stack **p_b, int n,
		t_dual_operation *op)
{
	while (n--)
		op(p_a, p_b);
}
