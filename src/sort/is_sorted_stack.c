/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:47:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:18:06 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

bool	is_sorted_stack(t_stack *st)
{
	int	current;

	current = 0;
	while (st)
	{
		if (get_content(st)->index != current)
			return (false);
		current++;
		st = st->next;
	}
	return (true);
}
