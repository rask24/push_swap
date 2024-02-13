/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/13 15:00:02 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef LEAK
# ifdef __APPLE__

void		leak_chek(void) __attribute__((destructor));

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

static void	_put_void(void *p_content)
{
	ft_printf("%d\n", ((t_content *)p_content)->index);
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	check_args(argc, argv);
	st_a = generate_stack(argc, argv);
	st_b = NULL;
	ft_lstiter(st_a, _put_void);
	sort(&st_a, &st_b);
	clear_stack(&st_a, free);
	return (0);
}
