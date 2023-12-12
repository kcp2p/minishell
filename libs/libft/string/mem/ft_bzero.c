/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:26:59 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:27:00 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset_nn(s, 0, n);
}
