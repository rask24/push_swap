/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:42:03 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/11 12:45:45 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

void	sort(t_stack **p_a, t_stack **p_b);
void	nano_sort(t_stack **p_a);
void	micro_sort(t_stack **p_a, t_stack **p_b);
void	large_sort(t_stack **p_a, t_stack **p_b);
bool	is_sorted_stack(t_stack *st);

#endif
