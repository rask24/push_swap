/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:28:02 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/24 16:55:35 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	second_content(t_stack **p_stack)
{
	return (((t_content *)(*p_stack)->next->content)->index);
}
