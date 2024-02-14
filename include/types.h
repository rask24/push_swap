/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:57:41 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/14 14:20:41 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef t_list	t_stack;

typedef enum e_method
{
	INIT,
	RA_RB,
	RRA_RB,
	RA_RRB,
	RRA_RRB,
}				t_method;

typedef struct s_content
{
	int			index;
	int			rb_cost;
	int			rrb_cost;
	int			ra_cost;
	int			rra_cost;
	int			min_cost;
	t_method	opt_method;
	bool		is_opt;
}				t_content;
#endif
