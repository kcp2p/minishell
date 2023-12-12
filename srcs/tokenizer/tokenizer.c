/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:25 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

/*
 [   aaa bbb cccc | echo hello world "good &"morning && test;cat<Makefile>out]
  ↓
 [aaa],[bbb],[cccc]		type:word
 [|],				 	type:operator
 [echo],[hello],[world]	type:word
 ["good &"morning]		type:word
 [&&]					type:operator
 [test]					type:word
 [;]					type:operator
 [cat]					type:word
 [<]					type:redirection
 [Makefile]				type:word
 [>]					type:redirection
 [out]					type:word
*/
int	tokenize_input_line(t_info *info, const char *readline_input)
{
	char	*space_trimmed_input;

	if (!info | !readline_input)
		return (PROCESS_ERROR);
	errno = 0;
	space_trimmed_input = ft_strtrim(readline_input, STR_SPACE);
	if (!space_trimmed_input)
		return (perror_ret_int("malloc", PROCESS_ERROR));
	if (ft_strlen_nn(space_trimmed_input) == 0)
	{
		free_ret_nullprt(space_trimmed_input);
		return (CONTINUE);
	}
	info->tokenlist_head = get_delim_splitted_tokenlist(\
	space_trimmed_input, STR_SPACE, STR_QUOTE);
	free_ret_nullprt(space_trimmed_input);
	if (!info->tokenlist_head)
		return (PROCESS_ERROR);
	if (split_by_operators(&info->tokenlist_head) == PROCESS_ERROR)
		return (PROCESS_ERROR);
	return (EXIT_SUCCESS);
}
