/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_continue_loop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:57:26 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:57:27 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

bool	is_eof_exit(int process_exit_value)
{
	if (process_exit_value == BREAK)
	{
		ft_dprintf(STDERR_FILENO, "exit\n");
		return (true);
	}
	return (false);
}

bool	is_minishell_abort(int process_exit_value)
{
	if (process_exit_value == PROCESS_ERROR)
	{
		ft_dprintf(STDERR_FILENO, "minishell: abort\n");
		return (true);
	}
	return (false);
}
