/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_before.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:54:29 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 16:54:44 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_before(t_list *lst, t_list *trg)
{
	t_list	*before;

	if (!lst)
		return (NULL);
	before = lst;
	while (before->next && before->next != trg)
		before = before->next;
	if (before->next != trg)
		return (NULL);
	return (before);
}
