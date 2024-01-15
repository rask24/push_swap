/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 13:04:27 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef DEV

# ifdef __APPLE__

__attribute__((destructor))
void	destructor(void)
{
	system("leaks -q push_swap");
}

# endif

void	put_void(void *content)
{
	puts(content);
}

#endif

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	check_args(argc, argv);
	stack_a = generate_stack(argc, argv);
	if (argc < 5)
		nano_sort(stack_a, argc);
	ft_lstclear(&stack_a, free);
	return (0);
}
