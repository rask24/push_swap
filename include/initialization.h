/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:30:37 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/11 12:33:50 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "push_swap.h"

int		check_args(int argc, char **argv);
t_stack	*generate_stack(int argc, char **argv);
void	exit_with_error(void);

#endif
