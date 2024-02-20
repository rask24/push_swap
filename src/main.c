/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:21:01 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"
#include "sort.h"

#ifdef LEAK
# ifdef __APPLE__

void	leak_check(void) __attribute__((destructor));

void	leak_check(void)
{
	system("leaks -q push_swap");
}

# endif
#endif

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	check_args(argc, argv);
	st_a = generate_stack(argc, argv);
	st_b = NULL;
	sort(&st_a, &st_b);
	clear_stack(&st_a, free);
	return (0);
}
