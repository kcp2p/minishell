/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:13:34 by krchuaip          #+#    #+#             */
/*   Updated: 2023/11/30 11:13:35 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_int_handler(int sig_num)
{
	if (sig_num == SIGINT)
		exit(130);
}

static void	execute_quit_handler(int sig_num)
{
	if (sig_num == SIGQUIT)
		exit(131);
}

void	init_signal_execute(void)
{
	struct sigaction	sig_int_act;
	struct sigaction	sig_quit_act;

	ft_bzero(&sig_int_act, sizeof(sigaction));
	ft_bzero(&sig_quit_act, sizeof(sigaction));
	init_sigaction(SIGINT, sig_int_act, execute_int_handler);
	init_sigaction(SIGQUIT, sig_quit_act, execute_quit_handler);
}
