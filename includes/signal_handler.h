/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:02:51 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <signal.h>

/* ************************** */
/*          typedef           */
/* ************************** */
typedef void	t_sigfunc(int);

/* ************************** */
/*          signal            */
/* ************************** */
void			init_signal_prompt(void);
void			init_sigaction(int sig_no, struct sigaction sig_act,
					t_sigfunc *sig_handler);
void			init_signal_execute(void);
int				print_signal_error(int exit_status, t_list_bi *node,
					t_list_bi *last_node);
int				do_heredoc(int fd, t_redirect_info *redirect_info);

#endif //SIGNAL_HANDLER_H
