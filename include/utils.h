/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:39:00 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/11 12:39:47 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

void		clear_stack(t_stack **p_stack, void (*del)(void *));
t_content	*get_content(t_stack *st);
int			get_first_index(t_stack **p_stack);
int			get_second_index(t_stack **p_stack);
int			get_third_index(t_stack **p_stack);
int			stack_size(t_stack *stack);

#endif
