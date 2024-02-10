/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_third_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:28:02 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/10 20:57:07 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_third_index(t_stack **p_stack)
{
	return (((t_content *)(*p_stack)->next->next->content)->index);
}
