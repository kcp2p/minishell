/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:45 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	define_key_value(char *cmd, t_export_info *e_info)
{
	char	*key_sign;
	int		exit_status;
	ssize_t	equal_index;
	ssize_t	cmd_len;

	exit_status = EXIT_SUCCESS;
	equal_index = 0;
	key_sign = ft_strchr(cmd, '=');
	if (key_sign == NULL)
	{
		e_info->key_type = e_novalue;
		e_info->key = ft_strdup_nn(cmd);
		return (exit_status);
	}
	cmd_len = ft_strlen(cmd);
	while (cmd[equal_index] != '=')
		equal_index++;
	e_info->key = ft_substr(cmd, 0, equal_index);
	e_info->value = ft_substr(cmd, equal_index + 1, (cmd_len - (equal_index
					+ 1)));
	if (!e_info->key || !e_info->value)
		return (perror_and_return_int("malloc", EXIT_FAILURE));
	return (exit_status);
}

static t_export_info	*init_export_info(void)
{
	t_export_info	*e_info;

	e_info = malloc(sizeof(t_export_info));
	if (!e_info)
		return (perror_ret_nullptr("malloc"));
	e_info->key = NULL;
	e_info->value = NULL;
	e_info->key_type = e_typeinit;
	return (e_info);
}

static void	pwd_flag_controller(t_list *node, char *key)
{
	t_env_elem	*elem;

	if (is_same_str(key, "PWD+"))
		key = "PWD";
	while (node != NULL)
	{
		elem = node->content;
		if (is_same_str(elem->key, key))
			elem->not_print = 0;
		node = node->next;
	}
}

static int	export_cmd(t_info *info, t_export_info *e_info, char **cmds)
{
	int	exit_status;

	exit_status = define_key_value(*cmds, e_info);
	e_info->key_type = judge_info_key(e_info);
	if (e_info->key_type == e_append || e_info->key_type == e_add)
		e_info->key_type = judge_value(e_info);
	if (e_info->key_type == e_error || e_info->key_type == e_nokey)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: export: `%s': not a valid identifier\n", *cmds);
		e_info->key = free_ret_nullprt(e_info->key);
		e_info->value = free_ret_nullprt(e_info->value);
		return (EXIT_FAILURE);
	}
	if (is_same_str(e_info->key, "PWD") || is_same_str(e_info->key,
			"OLDPWD") || is_same_str(e_info->key, "PWD+"))
		pwd_flag_controller(info->envlist_head, e_info->key);
	if (e_info->key_type == e_append)
		exit_status = append_env(info, e_info->key, e_info->value);
	if (e_info->key_type == e_add || e_info->key_type == e_novalue)
		exit_status = add_env(info, e_info->key, e_info->value);
	return (exit_status);
}

int	ft_export(t_info *info, char **cmds)
{
	int				exit_status;
	t_export_info	*e_info;

	exit_status = EXIT_SUCCESS;
	if (!info || !cmds)
		return (EXIT_FAILURE);
	e_info = init_export_info();
	if (!e_info)
		return (EXIT_FAILURE);
	cmds++;
	if (*cmds == NULL)
		exit_status = ft_sort_env(info);
	while (*cmds != NULL)
	{
		exit_status += export_cmd(info, e_info, cmds);
		init_key_value(e_info);
		cmds++;
	}
	e_info = free_ret_nullprt(e_info);
	if (exit_status > 0)
		return (EXIT_FAILURE);
	return (exit_status);
}
