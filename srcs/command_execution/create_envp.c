/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:38 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:52:40 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_execution.h"

/* create str: key=value if value is not NULL */
static char	*create_environ_str(t_env_elem *env_elem)
{
	char	*environ_str;

	if (!env_elem->key || !env_elem->value)
		return (NULL);
	environ_str = NULL;
	environ_str = concat_dst_to_src(&environ_str, env_elem->key);
	if (!environ_str)
		return (perror_ret_nullptr("malloc"));
	environ_str = concat_dst_to_src(&environ_str, "=");
	if (!environ_str)
		return (perror_ret_nullptr("malloc"));
	environ_str = concat_dst_to_src(&environ_str, env_elem->value);
	if (!environ_str)
		return (perror_ret_nullptr("malloc"));
	return (environ_str);
}

/* count elem if value exists */
static size_t	get_valid_envlist_size(t_list *env_list)
{
	size_t		cnt;
	t_env_elem	*env_elem;

	cnt = 0;
	while (env_list)
	{
		env_elem = env_list->content;
		if (env_elem && env_elem->key && env_elem->value)
			cnt++;
		env_list = env_list->next;
	}
	return (cnt);
}

char	**create_minishell_envp(t_list *envlist_head)
{
	const size_t	array_size = get_valid_envlist_size(envlist_head);
	char			**minishell_envp;
	size_t			idx;
	t_env_elem		*env_elem;

	minishell_envp = (char **) ft_calloc(sizeof(char *), array_size + 1);
	if (!minishell_envp)
		return (perror_ret_nullptr("malloc"));
	idx = 0;
	while (envlist_head && idx < array_size)
	{
		env_elem = envlist_head->content;
		if (env_elem->key && env_elem->value)
		{
			minishell_envp[idx] = create_environ_str(env_elem);
			if (!minishell_envp[idx])
			{
				free_2d_alloc((void **)minishell_envp);
				return (NULL);
			}
			idx++;
		}
		envlist_head = envlist_head->next;
	}
	return (minishell_envp);
}
