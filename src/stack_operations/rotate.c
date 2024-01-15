/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:05:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 14:32:12y reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*second;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
}

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

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*before_last;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	before_last = ft_lst_before(*stack, last);
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
