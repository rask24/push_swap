/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/10 20:56:41 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

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

int				check_args(int argc, char **argv);

t_stack			*generate_stack(int argc, char **argv);

void			sort(t_stack **p_a, t_stack **p_b, int num_a);
void			nano_sort(t_stack **p_a, int num_a);
void			micro_sort(t_stack **p_a, t_stack **p_b, int num_a);
void			large_sort(t_stack **p_a, t_stack **p_b, int num_a);
void			set_cost(t_stack **p_a, t_stack **p_b);
void			set_opt(t_stack **p_b);
void			greedy_operation(t_stack **p_a, t_stack **p_b);
bool			is_sorted_stack(t_stack *st);

void			operate_sa(t_stack **p_a);
void			operate_sb(t_stack **p_b);
void			operate_ss(t_stack **p_a, t_stack **p_b);
void			operate_ra(t_stack **p_a);
void			operate_rb(t_stack **p_b);
void			operate_rr(t_stack **p_a, t_stack **p_b);
void			operate_rra(t_stack **p_a);
void			operate_rrb(t_stack **p_a);
void			operate_rrr(t_stack **p_a, t_stack **p_b);
void			operate_pa(t_stack **p_b, t_stack **p_a);
void			operate_pb(t_stack **p_a, t_stack **p_b);
void			do_single_n_operations(t_stack **p_st, int n,
					void (*operation)(t_stack **));
void			do_double_n_operations(t_stack **p_a, t_stack **p_b, int n,
					void (*operation)(t_stack **, t_stack **));

void			push_stack(t_stack **p_s1, t_stack **p_s2);
void			swap_stack(t_stack **p_stack);
void			rotate_stack(t_stack **p_stack);
void			reverse_rotate_stack(t_stack **p_stack);

int				get_first_index(t_stack **p_stack);
int				get_second_index(t_stack **p_stack);
int				get_third_index(t_stack **p_stack);
void			exit_with_error(void);
void			clear_stack(t_stack **p_stack, void (*del)(void *));
int				stack_size(t_stack *stack);
t_content		*get_content(t_stack *st);

#endif
