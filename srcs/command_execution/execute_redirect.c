/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:50:52 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_execution.h"

static int	expand_var_in_heredoc(t_command_info *command_info, t_info *info)
{
	t_list_bi		*redirect_list;
	t_redirect_info	*r_info;

	if (!command_info || !info)
		return (FAILURE);
	redirect_list = command_info->redirect_list;
	while (redirect_list)
	{
		r_info = redirect_list->content;
		if (r_info->io_type == e_heredoc && r_info->is_expansion)
		{
			if (do_expansion_in_heredoc(r_info->filename, info) == FAILURE)
				return (FAILURE);
		}
		redirect_list = redirect_list->next;
	}
	return (SUCCESS);
}

static int	open_redirect_files(t_command_info **cmd_info, t_list_bi *r_list)
{
	t_redirect_info	*r_info;
	int				fd_idx;

	while (r_list)
	{
		r_info = r_list->content;
		if (r_info->is_ambiguous)
			return (ambiguous_error(r_info->filename));
		fd_idx = get_io_fd(r_info->io_type);
		if ((*cmd_info)->redirect_fd[fd_idx] != -1)
			if (close((*cmd_info)->redirect_fd[fd_idx]) < 0)
				return (perror_and_return_int("close", FAILURE));
		(*cmd_info)->redirect_fd[fd_idx] = get_openfile_fd(\
		r_info->filename, get_fopen_type(r_info->io_type));
		if ((*cmd_info)->redirect_fd[fd_idx] < 0)
			return (openfile_error(r_info->filename, strerror(errno)));
		r_list = r_list->next;
	}
	return (SUCCESS);
}

static int	dup2_and_close_fds(t_command_info **command_info)
{
	if (!command_info || !*command_info)
		return (FAILURE);
	if ((*command_info)->redirect_fd[FD_INFILE] != -1)
	{
		if (close(STDIN_FILENO) < 0)
			return (perror_and_return_int("close", FAILURE));
		if (dup2((*command_info)->redirect_fd[FD_INFILE], STDIN_FILENO) < 0)
			return (perror_and_return_int("dup2", FAILURE));
		if (close((*command_info)->redirect_fd[FD_INFILE]) < 0)
			return (perror_and_return_int("close", FAILURE));
	}
	if ((*command_info)->redirect_fd[FD_OUTFILE] != -1)
	{
		if (close(STDOUT_FILENO) < 0)
			return (perror_and_return_int("close", FAILURE));
		if (dup2((*command_info)->redirect_fd[FD_OUTFILE], STDOUT_FILENO) < 0)
			return (perror_and_return_int("dup2", FAILURE));
		if (close((*command_info)->redirect_fd[FD_OUTFILE]) < 0)
			return (perror_and_return_int("close", FAILURE));
	}
	return (SUCCESS);
}

static int	connect_redirect_fds(t_command_info **command_info)
{
	t_list_bi		*redirect_list;

	if (!command_info || !*command_info)
		return (FAILURE);
	if (!(*command_info)->redirect_list)
		return (SUCCESS);
	redirect_list = (*command_info)->redirect_list;
	if (open_redirect_files(command_info, redirect_list) == FAILURE)
		return (FAILURE);
	if (dup2_and_close_fds(command_info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	execute_redirect(t_command_info *command_info, t_info *info)
{
	if (!command_info)
		return (FAILURE);
	if (!command_info->redirect_list)
		return (SUCCESS);
	if (expand_var_in_heredoc(command_info, info) == FAILURE)
		return (FAILURE);
	if (connect_redirect_fds(&command_info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
