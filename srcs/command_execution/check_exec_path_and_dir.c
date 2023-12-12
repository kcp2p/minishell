/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec_path_and_dir.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:51:57 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:58:17 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_execution.h"

bool	is_path(const char *commands_head)
{
	if (commands_head \
	&& (commands_head[0] == '/' \
	|| (commands_head[0] == '.' && commands_head[1] == '/')))
		return (true);
	return (false);
}

void	check_is_a_dir_exit_if_dir(const char *commands_head)
{
	const size_t	len = ft_strlen_nn(commands_head);
	size_t			slash_cnt;
	size_t			dot_cnt;

	if (len == 0)
		return ;
	slash_cnt = count_char('/', commands_head);
	dot_cnt = count_char('.', commands_head);
	if (len == 1 && dot_cnt == 1)
	{
		ft_dprintf(STDERR_FILENO, ERRMSG_FILENAMEARG, commands_head);
		exit (FILENAME_REQUIRED);
	}
	if (len == slash_cnt + dot_cnt)
	{
		ft_dprintf(STDERR_FILENO, ERRMSG_IS_A_DIR, commands_head);
		exit (IS_A_DIR);
	}
}
