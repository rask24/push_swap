/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:41:01 by reasuke           #+#    #+#             */
/*   Updated: 2024/04/20 15:24:23 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H

# include "push_swap.h"

void	push_stack(t_stack **p_s1, t_stack **p_s2);
void	swap_stack(t_stack **p_stack);
void	rotate_stack(t_stack **p_stack);
void	reverse_rotate_stack(t_stack **p_stack);

void	repeat_stack_operations(t_stack **p_st, int n,
			void (*operation)(t_stack **));
void	do_double_n_operations(t_stack **p_a, t_stack **p_b, int n,
			void (*operation)(t_stack **, t_stack **));

void	operate_sa(t_stack **p_a);
void	operate_sb(t_stack **p_b);
void	operate_ss(t_stack **p_a, t_stack **p_b);
void	operate_ra(t_stack **p_a);
void	operate_rb(t_stack **p_b);
void	operate_rr(t_stack **p_a, t_stack **p_b);
void	operate_rra(t_stack **p_a);
void	operate_rrb(t_stack **p_a);
void	operate_rrr(t_stack **p_a, t_stack **p_b);
void	operate_pa(t_stack **p_b, t_stack **p_a);
void	operate_pb(t_stack **p_a, t_stack **p_b);

#endif
