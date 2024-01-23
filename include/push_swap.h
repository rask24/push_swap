/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/23 15:20:44 by reasuke          ###   ########.fr       */
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

typedef t_list	t_stack;

int		check_args(int argc, char **argv);

t_stack	*generate_stack(int argc, char **argv);

void	sort(t_stack **stack_a, t_stack **stack_b, int num_a);
void	nano_sort(t_stack **stack, int num_a);
void	micro_sort(t_stack **stack_a, t_stack **stack_b, int num_a);

void	operate_sa(t_stack **stack_a);
void	operate_sb(t_stack **stack_b);
void	operate_ra(t_stack **stack_a);
void	operate_rra(t_stack **stack_a);
void	operate_pa(t_stack **stack_b, t_stack **stack_a);
void	operate_pb(t_stack **stack_a, t_stack **stack_b);
void	push_stack(t_stack **stack_1, t_stack **stack_2);
void	swap_stack(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
t_list	*ft_lst_before(t_list *lst, t_list *trg);

int		first_content(t_stack **stack);
int		second_content(t_stack **stack);
void	exit_with_error(void);

#endif
