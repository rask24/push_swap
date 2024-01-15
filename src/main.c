/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 16:34:16 by reasuke          ###   ########.fr       */
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
	ft_printf("%d\n", *(int *)content);
}

#endif

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	check_args(argc, argv);
	stack_a = generate_stack(argc, argv);
	stack_b = NULL;
	ft_lstiter(stack_a, put_void);
	sort(&stack_a, &stack_b, argc);
	ft_lstiter(stack_a, put_void);
	ft_lstclear(&stack_a, free);
	return (0);
}
