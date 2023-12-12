/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:35 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_execution.h"

bool	is_single_builtin(t_list_bi *pipeline_cmds_head)
{
	t_command_info	*command_info;

	command_info = pipeline_cmds_head->content;
	if (!command_info->commands)
		return (false);
	if (!is_builtin(command_info->commands))
		return (false);
	if (ft_lstsize_bi(pipeline_cmds_head) > 1)
		return (false);
	if (command_info->redirect_list)
		return (false);
	return (true);
}

bool	is_builtin(char **cmds)
{
	if (!cmds || !*cmds)
		return (false);
	if (is_same_str("env", cmds[0]))
		return (true);
	if (is_same_str("export", cmds[0]))
		return (true);
	if (is_same_str("unset", cmds[0]))
		return (true);
	if (is_same_str("echo", cmds[0]))
		return (true);
	if (is_same_str("pwd", cmds[0]))
		return (true);
	if (is_same_str("cd", cmds[0]))
		return (true);
	if (is_same_str("exit", cmds[0]))
		return (true);
	return (false);
}

int	execute_builtin(t_info *info, char **cmds, bool in_pipe)
{
	if (!cmds || !*cmds)
		return (EXIT_FAILURE);
	if (is_same_str("env", cmds[0]))
		return (ft_env(info, cmds));
	if (is_same_str("export", cmds[0]))
		return (ft_export(info, cmds));
	if (is_same_str("unset", cmds[0]))
		return (ft_unset(info, cmds));
	if (is_same_str("echo", cmds[0]))
		return (ft_echo(cmds));
	if (is_same_str("pwd", cmds[0]))
		return (ft_pwd(info));
	if (is_same_str("cd", cmds[0]))
		return (ft_cd(info, cmds));
	if (is_same_str("exit", cmds[0]))
		return (ft_exit(info, cmds, in_pipe));
	return (EXIT_FAILURE);
}
