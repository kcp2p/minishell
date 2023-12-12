/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_fork_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:14 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:52:15 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_execution.h"

bool	is_fork_failure(pid_t pid)
{
	return (pid < 0);
}

bool	is_child_process(pid_t pid)
{
	return (pid == 0);
}

bool	is_parent_process(pid_t pid)
{
	return (pid > 0);
}
