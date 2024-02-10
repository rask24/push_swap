/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/10 21:19:08 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef LEAK
# ifdef __APPLE__

void	leak_chek(void) __attribute__((destructor));

void	leak_chek(void)
{
	system("leaks -q push_swap");
}

# endif
#endif
#ifdef DEV

void	put_void(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

#endif

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	check_args(argc, argv);
	a = generate_stack(argc, argv);
	b = NULL;
	sort(&a, &b);
	clear_stack(&a, free);
	return (0);
}
