/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_for_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:24:44 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:24:44 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

ssize_t	ft_putchar_for_printf(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	ft_putstr_for_printf(char *s, int fd)
{
	ssize_t	put_bytes;

	put_bytes = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		errno = 0;
		put_bytes += ft_putchar_for_printf(*s++, fd);
		if (errno != 0)
		{
			perror("write");
			return (-1);
		}
		if (put_bytes > INT_MAX)
			return (-1);
	}
	return (put_bytes);
}
