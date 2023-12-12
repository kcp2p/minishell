/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:02:27 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 15:02:39 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>
# include <termios.h>
# include <unistd.h>

# include <readline/readline.h>
# include <readline/history.h>

# include "minishell.h"

/* ************************** */
/*          typedef           */
/* ************************** */
typedef struct s_info	t_info;

/* ************************** */
/*           input            */
/* ************************** */
int		prompt_loop(t_info *info);
char	*get_prompt(int exit_status);
void	clear_input_info(t_info **info);
int		set_tc_attr_out_execute(void);
int		set_tc_attr_in_execute(void);
bool	is_eof_exit(int process_exit_value);
bool	is_minishell_abort(int process_exit_value);

#endif //INPUT_H
