/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 15:13:28 by reasuke          ###   ########.fr       */
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

void	sort(t_list **stack, int argc);
void	nano_sort(t_list **stack, int num_of_element);

void	swap_stack(t_list **stack);
void	rotate_stack(t_list **stack);
void	reverse_rotate_stack(t_list **stack);
t_list	*ft_lst_before(t_list *lst, t_list *trg);

void	exit_with_error(void);

#endif
