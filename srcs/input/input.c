/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:57:33 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:57:34 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_gbl_var	g_status;

void	prompt_int_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		g_status.exit_status = EXIT_FAILURE;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	prompt_init(int *process_exit_value, t_info *info)
{
	char	*prompt;

	if (*process_exit_value == EXIT_BY_SIG)
		info->exit_status = EXIT_FAILURE;
	else if (*process_exit_value != CONTINUE)
		info->exit_status = *process_exit_value;
	*process_exit_value = EXIT_SUCCESS;
	g_status.exit_status = EXIT_SUCCESS;
	set_tc_attr_out_execute();
	init_signal_prompt();
	prompt = get_prompt(info->exit_status);
	if (!prompt)
	{
		*process_exit_value = PROCESS_ERROR;
		return ;
	}
	info->readline_input = readline(prompt);
	free(prompt);
}

static int	preprocess_for_execute(t_info *info)
{
	int	process_exit_val;

	if (!info->readline_input)
		return (BREAK);
	if (is_same_str(info->readline_input, ""))
	{
		info->readline_input = free_ret_nullprt(info->readline_input);
		return (CONTINUE);
	}
	add_history(info->readline_input);
	process_exit_val = tokenize_input_line(info, info->readline_input);
	if (process_exit_val == CONTINUE)
		return (CONTINUE);
	if (process_exit_val == EXIT_SUCCESS)
		process_exit_val = arrange_and_validate_token_list(\
		&info->tokenlist_head);
	if (process_exit_val == EXIT_SUCCESS)
		process_exit_val = parsing_token_list(\
				&info->tokenlist_head, &info->execlist_head, info);
	return (process_exit_val);
}

static void	update_exit_status(t_info *info)
{
	if (g_status.exit_status == EXIT_FAILURE)
		info->exit_status = g_status.exit_status;
}

int	prompt_loop(t_info *info)
{
	int	process_exit_value;

	if (!info)
		return (FAILURE);
	process_exit_value = EXIT_SUCCESS;
	while (true)
	{
		prompt_init(&process_exit_value, info);
		if (is_minishell_abort(process_exit_value))
			break ;
		process_exit_value = preprocess_for_execute(info);
		if (is_eof_exit(process_exit_value))
			break ;
		update_exit_status(info);
		if (process_exit_value == EXIT_SUCCESS)
			process_exit_value = execute_execlist(&info->execlist_head, info);
		clear_input_info(&info);
		if (is_minishell_abort(process_exit_value))
			break ;
	}
	set_tc_attr_in_execute();
	return (info->exit_status);
}
