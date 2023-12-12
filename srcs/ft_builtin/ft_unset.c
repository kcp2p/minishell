/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:32 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:55:37 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unset_elem(t_list *pre_node, t_list *cur_node, t_info *info)
{
	t_list	*next_node;

	if (pre_node == NULL)
	{
		next_node = cur_node->next;
		ft_lstdelone(cur_node, free_env_elem);
		info->envlist_head = next_node;
	}
	else
	{
		pre_node->next = cur_node->next;
		ft_lstdelone(cur_node, free_env_elem);
	}
	return (EXIT_SUCCESS);
}

static int	unset_pwd(t_env_elem *elem)
{
	char	*temp;

	elem->not_print = 1;
	temp = elem->value;
	elem->value = NULL;
	free(temp);
	return (EXIT_SUCCESS);
}

static int	unset_env(t_info *info, char *cmd)
{
	t_list	*pre_node;
	t_list	*env_node;

	pre_node = NULL;
	env_node = info->envlist_head;
	while (env_node != NULL)
	{
		if (get_value_from_key(env_node->content, cmd) != NULL)
		{
			if (is_same_str("PWD", cmd) || is_same_str("OLDPWD", cmd))
				return (unset_pwd(env_node->content));
			return (unset_elem(pre_node, env_node, info));
		}
		pre_node = env_node;
		env_node = env_node->next;
	}
	return (EXIT_SUCCESS);
}

int	ft_unset(t_info *info, char **cmds)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (!info || !cmds)
		return (EXIT_FAILURE);
	cmds++;
	while (*cmds != NULL)
	{
		if (judge_chr_key(*cmds) == FAILURE)
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: unset: `%s': not a valid identifier\n",
				*cmds);
			exit_status += EXIT_FAILURE;
		}
		else
			exit_status += unset_env(info, *cmds);
		cmds++;
	}
	if (exit_status > 0)
		return (EXIT_FAILURE);
	return (exit_status);
}
