/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:21 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_execution.h"

int	execute_subshell(t_list_bi **token_list, t_info *info)
{
	t_exec_list	*exec_list;
	int			exit_status;

	if (!token_list || !info)
		return (PROCESS_ERROR);
	exec_list = NULL;
	if (parsing_token_list(token_list, &exec_list, info) == PROCESS_ERROR)
	{
		clear_exec_list(&exec_list);
		return (PROCESS_ERROR);
	}
	exit_status = execute_execlist(&exec_list, info);
	clear_exec_list(&exec_list);
	return (exit_status);
}
