/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:01 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

/* command_list->redirect_list = heredoc->io->io->heredoc->... */
/* if type=io, expand and create filename
 * from redirect_list->content=redirect_info->token_list */
int	expand_var_and_create_cmds_from_tokens(\
t_exec_list **pipeline_node, t_info *info)
{
	t_list_bi		*cmd_list_node;
	t_command_info	*cmd_info;

	if (!pipeline_node || !info)
		return (FAILURE);
	cmd_list_node = (*pipeline_node)->pipeline_commands;
	while (cmd_list_node)
	{
		cmd_info = cmd_list_node->content;
		if (cmd_info->pipeline_token_list)
		{
			cmd_info->commands = create_expanded_commands(\
			&cmd_info->pipeline_token_list, info, NULL);
			if (!cmd_info->commands)
				return (FAILURE);
		}
		if (expand_var_in_redirect_filename(&cmd_info, info) == FAILURE)
			return (FAILURE);
		cmd_list_node = cmd_list_node->next;
	}
	return (SUCCESS);
}
