/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:25:05 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:25:05 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_put.h"

static void	recursion_put_nbr(int num, int fd)
{
	if (num == 0)
		return ;
	recursion_put_nbr(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n >= 0)
		num = n;
	else
	{
		num = -n;
		ft_putchar_fd('-', fd);
	}
	recursion_put_nbr(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}
