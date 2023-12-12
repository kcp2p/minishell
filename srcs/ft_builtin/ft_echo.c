/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:54 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:55:55 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	judge_n_option(char *cmd)
{
	if (*cmd != '-')
		return (FAILURE);
	cmd++;
	if (!*cmd)
		return (FAILURE);
	while (*cmd != '\0')
	{
		if (*cmd != 'n')
			return (FAILURE);
		cmd++;
	}
	return (SUCCESS);
}

static void	printf_cmds(char **cmds)
{
	size_t	i;

	i = 0;
	while (*cmds != NULL)
	{
		if (i == 0)
			ft_printf("%s", *cmds);
		else
			ft_printf(" %s", *cmds);
		cmds++;
		i++;
	}
}

int	ft_echo(char **cmds)
{
	int	n_flag;

	n_flag = 0;
	if (!cmds)
		return (EXIT_FAILURE);
	cmds++;
	while (*cmds != NULL)
	{
		if (judge_n_option(*cmds) == SUCCESS)
		{
			n_flag = 1;
			cmds++;
		}
		else
		{
			printf_cmds(cmds);
			break ;
		}
	}
	if (n_flag != 1)
		ft_printf("\n");
	return (EXIT_SUCCESS);
}
