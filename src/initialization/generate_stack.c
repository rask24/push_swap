/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:04:40 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/20 14:19:17 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

int	*_allocate_int_array(int size_a)
{
	int	*array;

	array = malloc(sizeof(int) * size_a);
	if (!array)
		exit_with_error();
	return (array);
}

int	*_generate_numberd_array(int size_a, char **argv)
{
	int	i;
	int	*numberd;

	numberd = _allocate_int_array(size_a);
	i = 0;
	while (i < size_a)
	{
		numberd[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (numberd);
}

int	*_generate_sorted_array(int size_a, char **argv)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = _generate_numberd_array(size_a, argv);
	i = size_a - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (sorted[j] > sorted[j + 1])
				ft_swap(sorted + j, sorted + j + 1);
			j++;
		}
		i--;
	}
	return (sorted);
}

int	*_coordinate_compression(int size_a, char **argv)
{
	int	*comp;
	int	*sorted;
	int	i;
	int	j;

	comp = _allocate_int_array(size_a);
	sorted = _generate_sorted_array(size_a, argv);
	i = 0;
	while (i < size_a)
	{
		j = 0;
		while (j < size_a)
		{
			if (ft_atoi(argv[i + 1]) == sorted[j])
				comp[i] = j;
			j++;
		}
		i++;
	}
	free(sorted);
	return (comp);
}

t_stack	*generate_stack(int argc, char **argv)
{
	t_stack		*st;
	int			*comp;
	int			i;
	t_content	*ptr;
	int			size_a;

	size_a = argc - 1;
	comp = _coordinate_compression(size_a, argv);
	i = 0;
	st = NULL;
	while (i < size_a)
	{
		ptr = ft_calloc(1, sizeof(t_content));
		if (!ptr)
			exit_with_error();
		ptr->index = comp[i];
		ptr->segment = -1;
		ft_lstadd_back(&st, ft_lstnew(ptr));
		i++;
	}
	free(comp);
	return (st);
}
