/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:24:55 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:24:56 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_put.h"

ssize_t	ft_putchar_fd(char c, int fd)
{
	ssize_t	ret;

	errno = 0;
	ret = write(fd, &c, sizeof(char));
	if (ret < 0)
		perror("write");
	return (ret);
}
