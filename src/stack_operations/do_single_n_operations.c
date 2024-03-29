/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_single_n_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:22:26 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:15:35 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	do_single_n_operations(t_stack **p_st, int n,
		void (*operation)(t_stack **))
{
	while (n--)
		operation(p_st);
}
