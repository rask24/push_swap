/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/12 16:09:00 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef DEV

__attribute__((destructor))
void	destructor(void)
{
	system("leaks -q push_swap");
}

void	put_void(void *content)
{
	puts(content);
}

#endif

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	if (is_invalid_argument(argc, argv))
		exit_with_error();
	stack_a = generate_stack(argc, argv);
	if (argc < 4)
		nano_sort(stack_a, argc);
	ft_lstclear(&stack_a, free);
	return (0);
}
