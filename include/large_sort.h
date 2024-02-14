/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:36:38 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/14 16:41:29 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LARGE_SORT_H
# define LARGE_SORT_H

# include "push_swap.h"

void	large_sort(t_stack **p_a, t_stack **p_b);
void	push_b_segmented(t_stack **p_a, t_stack **p_b, int n, int num_seg);
void	set_cost(t_stack **p_a, t_stack **p_b);
void	set_min_cost_opt_method(t_stack **p_b);
void	set_is_target(t_stack **p_b);
void	greedy_operation(t_stack **p_a, t_stack **p_b);

#endif
