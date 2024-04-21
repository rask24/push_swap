/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_stack_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:22:26 by reasuke           #+#    #+#             */
/*   Updated: 2024/04/21 16:27:24 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	repeat_stack_operations(t_stack **p_st, int n, t_operation op)
{
	while (n--)
		op(p_st);
}
