/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_double_n_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:22:50 by reasuke           #+#    #+#             */
/*   Updated: 2024/04/20 15:15:59 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	do_double_n_operations(t_stack **p_a, t_stack **p_b, int n,
		void (*operation)(t_stack **, t_stack **))
{
	while (n--)
		operation(p_a, p_b);
}
