/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:35 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 15:12:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack, int argc)
{
	int	num_of_element;

	num_of_element = argc - 1;
	if (num_of_element <= 3)
		nano_sort(stack, num_of_element);
}
