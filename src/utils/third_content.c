/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:28:02 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/07 15:06:04 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	third_content(t_stack **p_stack)
{
	return (((t_content *)(*p_stack)->next->next->content)->index);
}
