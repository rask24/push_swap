/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/17 16:05:34 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// TODO: delete
# include <stdio.h>

# include "../libft/libft.h"

int		check_args(int argc, char **argv);

t_list	*generate_stack(int argc, char **argv);

void	sort(t_list **stack_a, t_list **stack_b, int num_a);
void	nano_sort(t_list **stack, int num_a);
void	micro_sort(t_list **stack_a, t_list **stack_b, int num_a);

void	operate_sa(t_list **stack_a);
void	operate_ra(t_list **stack_a);
void	operate_rra(t_list **stack_a);
void	operate_pa(t_list **stack_b, t_list **stack_a);
void	operate_pb(t_list **stack_a, t_list **stack_b);
void	push_stack(t_list **stack_1, t_list **stack_2);
void	swap_stack(t_list **stack);
void	rotate_stack(t_list **stack);
void	reverse_rotate_stack(t_list **stack);
t_list	*ft_lst_before(t_list *lst, t_list *trg);

void	exit_with_error(void);

#endif
