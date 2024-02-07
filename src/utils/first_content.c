/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:27:37 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/07 15:05:41 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_content(t_stack **p_stack)
{
	return (((t_content *)(*p_stack)->content)->index);
}
