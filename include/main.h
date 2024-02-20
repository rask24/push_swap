/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:23:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/19 16:25:20 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "push_swap.h"

int		check_args(int argc, char **argv);
t_stack	*generate_stack(int argc, char **argv);

void	sort(t_stack **p_a, t_stack **p_b);

#endif
