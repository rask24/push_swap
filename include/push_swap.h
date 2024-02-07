/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/08 07:44:33 by reasuke          ###   ########.fr       */
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
typedef struct s_content
{
	int			index;
	int			sf_cost;
	int			sr_cost;
	int			if_cost;
	int			ir_cost;
}				t_content;

int				check_args(int argc, char **argv);

t_stack			*generate_stack(int argc, char **argv);

void			sort(t_stack **p_a, t_stack **p_b, int num_a);
void			nano_sort(t_stack **p_a, int num_a);
void			micro_sort(t_stack **p_a, t_stack **p_b, int num_a);
void			large_sort(t_stack **p_a, t_stack **p_b, int num_a);

void			set_selection_cost(t_stack **p_b);

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

void			push_stack(t_stack **p_s1, t_stack **p_s2);
void			swap_stack(t_stack **p_stack);
void			rotate_stack(t_stack **p_stack);
void			reverse_rotate_stack(t_stack **p_stack);
t_list			*ft_lst_before(t_list *lst, t_list *trg);

int				first_content(t_stack **p_stack);
int				second_content(t_stack **p_stack);
int				third_content(t_stack **p_stack);
void			exit_with_error(void);
void			clear_stack(t_stack **p_stack, void (*del)(void *));
int				stack_size(t_stack *stack);
t_content		*get_content(t_stack *st);

#endif
