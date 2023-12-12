/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:58:36 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:58:37 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	tree_clear(t_exec_list **stk)
{
	t_exec_list	*right;

	if (!stk)
		return ;
	while (*stk)
	{
		right = (*stk)->next;
		free(*stk);
		*stk = right;
	}
	*stk = NULL;
}

size_t	get_tree_size(t_exec_list *stk)
{
	size_t	size;

	size = 0;
	while (stk)
	{
		stk = stk->next;
		size++;
	}
	return (size);
}
