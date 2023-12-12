/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:48 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:55:49 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_cmds(char **cmds)
{
	int	count;

	count = 0;
	while (*cmds != NULL)
	{
		count++;
		cmds++;
	}
	return (count);
}

static int	cmd_to_ll(char **cmds)
{
	bool	is_strtoll_success;
	int		exit_status;
	char	*input_exit_num_chr;

	input_exit_num_chr = ft_strtrim(*cmds, " ");
	if (!input_exit_num_chr)
		return (EXIT_FAILURE);
	exit_status = (int)(ft_strtoll(input_exit_num_chr,
				&is_strtoll_success) % 256);
	free(input_exit_num_chr);
	if (!is_strtoll_success)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: exit: %s: numeric argument required\n",
			(char *)*cmds);
		return (255);
	}
	return (exit_status);
}

/* '--' is end of option */
int	ft_exit(t_info *info, char **cmds, bool in_pipe)
{
	int		exit_status;
	int		cmds_count;
	size_t	idx;

	if (!info || !cmds)
		return (EXIT_FAILURE);
	if (!in_pipe)
		ft_dprintf(STDERR_FILENO, "exit\n");
	idx = 1;
	if (is_same_str(cmds[idx], "--"))
		idx++;
	cmds_count = count_cmds(&cmds[idx]);
	exit_status = cmd_to_ll(&cmds[idx]);
	if (cmds_count > 1 && exit_status != 255)
	{
		ft_dprintf(STDERR_FILENO, "minishell: exit: too many arguments\n");
		return (EXIT_FAILURE);
	}
	if (cmds_count == 0)
		exit_status = info->exit_status;
	exit_status %= 256;
	exit(exit_status);
}
