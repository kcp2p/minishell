/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:18 by krchuaip          #+#    #+#             */
/*   Updated: 2023/11/29 18:56:19 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	is_tokentype_semicolon(t_token_type type)
{
	return (type == e_semicolon);
}

int	is_tokentype_pipe_and_or(t_token_type type)
{
	return (type == e_ope_pipe \
	|| type == e_ope_or \
	|| type == e_ope_and);
}

int	is_tokentype_redirection(t_token_type type)
{
	return (type == e_redirect_in \
	|| type == e_redirect_out \
	|| type == e_redirect_append \
	|| type == e_heredoc);
}

int	is_tokentype_subshell(t_token_type type)
{
	return (type == e_subshell_start \
	|| type == e_subshell_end);
}

int	is_tokentype_operator(t_token_type type)
{
	return (type == e_semicolon \
	|| type == e_ope_and \
	|| type == e_ope_or);
}
