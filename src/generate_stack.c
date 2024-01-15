/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:04:40 by reasuke           #+#    #+#             */
/*   Updated: 2024/01/15 12:56:26 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*_generate_int_array(int array_size)
{
	int	*array;

	array = malloc(sizeof(int) * array_size);
	if (!array)
		exit_with_error();
	return (array);
}

int	*_generate_numberd_array(int array_size, char **argv)
{
	int	i;
	int	*numberd_array;

	numberd_array = _generate_int_array(array_size);
	i = 0;
	while (i < array_size)
	{
		numberd_array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (numberd_array);
}

int	*_generate_sorted_array(int argc, char **argv)
{
	int	array_size;
	int	*sorted_array;
	int	i;
	int	j;

	array_size = argc - 1;
	sorted_array = _generate_numberd_array(array_size, argv);
	i = array_size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (sorted_array[j] > sorted_array[j + 1])
				ft_swap(sorted_array + j, sorted_array + j + 1);
			j++;
		}
		i--;
	}
	return (sorted_array);
}

int	*_coordinate_compression(int argc, char **argv)
{
	int	*compressred_array;
	int	*sorted_array;
	int	array_size;
	int	i;
	int	j;

	array_size = argc - 1;
	compressred_array = _generate_int_array(array_size);
	sorted_array = _generate_sorted_array(argc, argv);
	i = 0;
	while (i < array_size)
	{
		j = 0;
		while (j < array_size)
		{
			if (ft_atoi(argv[i + 1]) == sorted_array[j])
				compressred_array[i] = j + 1;
			j++;
		}
		i++;
	}
	free(sorted_array);
	return (compressred_array);
}

t_list	*generate_stack(int argc, char **argv)
{
	t_list	*stack;
	int		*compressed_array;
	int		i;
	int		*ptr;

	compressed_array = _coordinate_compression(argc, argv);
	i = 0;
	stack = NULL;
	while (i < argc - 1)
	{
		ptr = ft_calloc(1, sizeof(int));
		if (!ptr)
			exit_with_error();
		*ptr = compressed_array[i];
		ft_lstadd_back(&stack, ft_lstnew(ptr));
		i++;
	}
	free(compressed_array);
	return (stack);
}
