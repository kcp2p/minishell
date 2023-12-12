/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bdi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:24:18 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:24:18 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_list.h"

void	ft_lstdelone_bi(t_list_bi **lst, void (*del)(void *))
{
	if (!lst || !*lst)
		return ;
	if (del != NULL)
		(*del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
