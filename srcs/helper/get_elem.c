/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:56:49 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:56:50 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_value_from_key(t_env_elem *elem, char *key)
{
	if (is_same_str(elem->key, key))
		return (&elem->value);
	return (NULL);
}

char	**get_elem(t_info *info, char *key)
{
	t_list	*env_node;
	char	**value;

	env_node = info->envlist_head;
	value = NULL;
	while (env_node != NULL)
	{
		value = get_value_from_key(env_node->content, key);
		if (value != NULL)
			return (value);
		env_node = env_node->next;
	}
	return (value);
}
