/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:57:41 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/11 12:58:04 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef t_list	t_stack;

typedef enum e_method
{
	INIT,
	FF,
	FR,
	RF,
	RR,
}				t_method;

typedef struct s_content
{
	int			index;
	int			sf_cost;
	int			sr_cost;
	int			if_cost;
	int			ir_cost;
	int			min_cost;
	t_method	opt_method;
	bool		is_opt;
}				t_content;
#endif
