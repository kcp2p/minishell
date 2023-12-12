/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:56:39 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_elem(t_info *info, char *key, char *value)
{
	t_list		*new_env_node;
	t_env_elem	*new_elem;

	new_elem = malloc(sizeof(t_env_elem));
	if (!new_elem)
		return (perror_and_return_int("malloc", EXIT_FAILURE));
	new_elem->key = key;
	new_elem->value = value;
	new_elem->not_print = 0;
	new_env_node = ft_lstnew(new_elem);
	if (!new_env_node)
		return (perror_and_return_int("malloc", EXIT_FAILURE));
	else
		ft_lstadd_back(&info->envlist_head, new_env_node);
	return (EXIT_SUCCESS);
}

static void	append_elem(char **elem_value, char *elem_key, char *value)
{
	char	*temp_ptr;

	temp_ptr = *elem_value;
	if (*elem_value != NULL)
	{
		*elem_value = ft_strjoin(*elem_value, value);
		value = free_ret_nullprt(value);
	}
	else
		*elem_value = value;
	elem_key = free_ret_nullprt(elem_key);
	temp_ptr = free_ret_nullprt(temp_ptr);
}

int	append_env(t_info *info, char *key, char *value)
{
	char	**elem_value;
	ssize_t	key_len;
	char	*elem_key;

	key_len = ft_strlen(key);
	elem_key = malloc(sizeof(char) * (key_len));
	if (!elem_key)
		return (perror_and_return_int("malloc", EXIT_FAILURE));
	elem_key = ft_memmove(elem_key, key, key_len - 1);
	key = free_ret_nullprt(key);
	elem_value = get_elem(info, elem_key);
	if (elem_value == NULL)
		set_elem(info, elem_key, value);
	else
		append_elem(elem_value, elem_key, value);
	return (EXIT_SUCCESS);
}

int	add_env(t_info *info, char *key, char *value)
{
	int		exit_status;
	char	**elem_value;
	char	*temp_ptr;

	exit_status = EXIT_SUCCESS;
	elem_value = get_elem(info, key);
	if (elem_value != NULL && value != NULL)
	{
		temp_ptr = *elem_value;
		*elem_value = ft_strdup_nn(value);
		temp_ptr = free_ret_nullprt(temp_ptr);
		value = free_ret_nullprt(value);
		key = free_ret_nullprt(key);
	}
	else if (elem_value == NULL)
		exit_status = set_elem(info, key, value);
	else if (value == NULL)
		key = free_ret_nullprt(key);
	return (exit_status);
}
