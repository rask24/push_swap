/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:25:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/14 13:50:38 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "initialization.h"
#include "sort.h"
#include "stack_operations.h"

static bool	_is_operation_present(const char *op)
{
	bool	present;

	present = false;
	present |= !ft_strcmp(op, "sa\n");
	present |= !ft_strcmp(op, "sb\n");
	present |= !ft_strcmp(op, "ss\n");
	present |= !ft_strcmp(op, "pa\n");
	present |= !ft_strcmp(op, "pb\n");
	present |= !ft_strcmp(op, "ra\n");
	present |= !ft_strcmp(op, "rb\n");
	present |= !ft_strcmp(op, "rr\n");
	present |= !ft_strcmp(op, "rra\n");
	present |= !ft_strcmp(op, "rrb\n");
	present |= !ft_strcmp(op, "rrr\n");
	return (present);
}

static void	_stack_operation(t_stack **p_a, t_stack **p_b, const char *op)
{
	if (!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "ss\n"))
		swap_stack(p_a);
	if (!ft_strcmp(op, "sb\n") || !ft_strcmp(op, "ss\n"))
		swap_stack(p_b);
	if (!ft_strcmp(op, "pa\n"))
		push_stack(p_b, p_a);
	if (!ft_strcmp(op, "pb\n"))
		push_stack(p_a, p_b);
	if (!ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rr\n"))
		rotate_stack(p_a);
	if (!ft_strcmp(op, "rb\n") || !ft_strcmp(op, "rr\n"))
		rotate_stack(p_b);
	if (!ft_strcmp(op, "rra\n") || !ft_strcmp(op, "rrr\n"))
		reverse_rotate_stack(p_a);
	if (!ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rrr\n"))
		reverse_rotate_stack(p_b);
}

static void	_sort_based_on_operation(t_stack **p_a, t_stack **p_b)
{
	char	*op;

	while (true)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		if (!_is_operation_present(op))
			exit_with_error();
		_stack_operation(p_a, p_b, op);
	}
}

static void	_check_sorted(t_stack *st_a, int size_a)
{
	if (stack_size(st_a) != size_a)
		ft_putendl_fd("KO", STDOUT_FILENO);
	if (is_sorted_stack(st_a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc == 1)
		return (0);
	check_args(argc, argv);
	st_a = generate_stack(argc, argv);
	st_b = NULL;
	_sort_based_on_operation(&st_a, &st_b);
	_check_sorted(st_a, argc - 1);
	return (0);
}
