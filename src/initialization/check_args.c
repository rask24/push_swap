/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:44:55 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/13 11:45:54 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"
#include "push_swap.h"

static bool	_has_not_digit(int argc, char **argv)
{
	int		i;
	char	*end_ptr;

	i = 1;
	while (i < argc)
	{
		ft_strtol(argv[i], &end_ptr, 10);
		if (*end_ptr)
			return (true);
		i++;
	}
	return (false);
}

static bool	_has_overflow(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_strtol(argv[i], NULL, 10);
		if (num < INT_MIN || INT_MAX < num)
			return (true);
		i++;
	}
	return (false);
}

static bool	_has_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strtol(argv[i], NULL, 10) == ft_strtol(argv[j], NULL, 10))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	check_args(int argc, char **argv)
{
	if (_has_not_digit(argc, argv) || _has_overflow(argc, argv)
		|| _has_duplicate(argc, argv))
		exit_with_error();
	return (0);
}
