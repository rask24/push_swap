/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/11 20:14:28 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_void(void *content)
{
	puts(content);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	if (is_invalid_argument(argc, argv))
		exit_with_error();
	stack_a = generate_stack(argc, argv);
	ft_lstclear(&stack_a, NULL);
	return (0);
}
