/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:43 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:44 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

size_t	get_arr_size(char **array)
{
	size_t	size;

	size = 0;
	while (array && array[size])
		size++;
	return (size);
}
