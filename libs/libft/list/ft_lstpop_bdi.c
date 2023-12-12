/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_bdi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:24:32 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:24:32 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_list.h"

//               *lst------v *lst
// [prev_node]->[node]->[next_node]
// prev_node->next = next_node
// next_node->prev = prev_node
t_list_bi	*ft_lstpop_bi(t_list_bi **lst)
{
	t_list_bi	*popped_node;

	if (!lst || !*lst)
		return (NULL);
	popped_node = *lst;
	*lst = popped_node->next;
	if (popped_node->prev)
		popped_node->prev->next = *lst;
	if (*lst)
		(*lst)->prev = popped_node->prev;
	popped_node->prev = NULL;
	popped_node->next = NULL;
	return (popped_node);
}
