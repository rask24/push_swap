/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:25:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/19 12:49:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "initialization.h"
#include "sort.h"

#ifdef LEAK
# ifdef __APPLE__

void		leak_check(void) __attribute__((destructor));

void	leak_check(void)
{
	system("leaks -q checker");
}

# endif
#endif

static void	_check_sorted(t_stack *st_a, int size_a)
{
	if (stack_size(st_a) != size_a)
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
		return ;
	}
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
	sort_based_on_operation(&st_a, &st_b);
	_check_sorted(st_a, argc - 1);
	clear_stack(&st_a, free);
	clear_stack(&st_b, free);
	return (0);
}
