/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:00:58 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:16:39 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (perror_ret_nullptr("malloc"));
	info->envlist_head = get_envlist();
	if (!info->envlist_head)
	{
		info = free_ret_nullprt(info);
		return (FAILURE);
	}
	info->tokenlist_head = NULL;
	info->execlist_head = NULL;
	info->exit_status = EXIT_SUCCESS;
	return (info);
}

static void	display_ascii_art(void)
{
	ft_printf("           _       _      _          _ _ \n" \
	" _ __ ___ (_)_ __ (_)___ | |__   ___| | |\n" \
	"| '_ ` _ \\| | '_ \\| / __|| '_ \\ / _ \\ | |\n" \
	"| | | | | | | | | | \\__ \\| | | |  __/ | |\n" \
	"|_| |_| |_|_|_| |_|_|___/|_| |_|\\___|_|_|\n" \
	"                        By: krchuaip, from the depth of hell.\n");
}

int	main(int argc, char **argv)
{
	int		exit_status;
	t_info	*info;

	if (argc != 1 || !argv)
	{
		ft_dprintf(STDERR_FILENO, \
		"[Error]Too many argument.\n" \
		"       Execute minishell:$> ./minishell\n");
		return (EXIT_FAILURE);
	}
	info = init_info();
	if (!info)
		return (FAILURE);
	display_ascii_art();
	exit_status = prompt_loop(info);
	free_info(&info);
	return (exit_status);
}
