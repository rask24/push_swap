/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:28:02 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/17 18:29:17 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	second_content(t_list **stack)
{
	return (*(int *)(*stack)->next->content);
}
