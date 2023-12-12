/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:25:13 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:25:14 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_std.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	ret_ptr = malloc(count * size);
	if (ret_ptr == NULL)
		return (NULL);
	ft_bzero(ret_ptr, count * size);
	return (ret_ptr);
}
