/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:41:01 by reasuke           #+#    #+#             */
/*   Updated: 2024/04/21 16:30:51 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H

# include "push_swap.h"

typedef void	(*t_operation)(t_stack **);
typedef void	(*t_dual_operation)(t_stack **, t_stack **);

void	push_stack(t_stack **p_s1, t_stack **p_s2);
void	swap_stack(t_stack **p_stack);
void	rotate_stack(t_stack **p_stack);
void	reverse_rotate_stack(t_stack **p_stack);

void	repeat_stack_operations(t_stack **p_st, int n, t_operation op);
void	repeat_dual_stack_operations(t_stack **p_a, t_stack **p_b, int n,
			t_dual_operation op);

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
