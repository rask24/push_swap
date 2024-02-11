/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:38:17 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/11 12:35:14 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

void	exit_with_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}
