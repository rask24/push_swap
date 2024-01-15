/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/12 16:02:39 by reasuke          ###   ########.fr       */
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

bool	is_invalid_argument(int argc, char **argv);

t_list	*generate_stack(int argc, char **argv);

void	nano_sort(t_list *stack, int argc);

void	exit_with_error(void);

#endif
