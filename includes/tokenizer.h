/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:02:47 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

/*          typedef           */
typedef struct s_info			t_info;
typedef struct s_token_elem		t_token_elem;
typedef struct s_split_info		t_split_info;

typedef enum e_token_type		t_token_type;

/* ************************** */
/*         tokenize           */
/* ************************** */

/* tokenizer.c */
int				tokenize_input_line(t_info *info, const char *readline_input);

/* space_split.c */
t_list_bi		*get_delim_splitted_tokenlist(\
const char *src, const char *delim, const char *setchars);

/* create_split_info.c */
t_split_info	*create_split_info(\
const char *src, const char *delim, const char *set);
void			init_split_info(t_split_info *s_info);

/* operator_split.c */
int				split_by_operators(t_list_bi **token_head);

/* get_split_before_after_opes.c */
t_list_bi		*get_split_before_after_opes(\
const char *src, const char *opes, char *quote);

/* create_splitted_word_token.c */
t_token_elem	*create_splitted_word_token_from_src(t_split_info *s_info);

/* get_trimmed_word.c */
char			*get_trimmed_word(t_split_info *s_info);

/* arrange_and_validate_token.c */
int				arrange_and_validate_token_list(t_list_bi **tokenlist_head);

/* validate_quote.c */
int				validate_quote(t_list_bi *tokenlist_head);

/* validate_syntax.c */
int				validate_syntax_operators(t_list_bi *tokenlist_head);;
int				validate_syntax_parenthesis_pairs(t_list_bi *tokenlist_head);

/* validate_operator.c */
int				valid_control_operator(t_list_bi **tokenlist_head);

/* check_operator_syntax.c */
int				validate_operator_tokens(\
t_token_elem *now_token, t_token_elem *next_token, bool is_head);

/* create_token_elem.c */
t_token_elem	*create_token_elem(\
char *word, bool is_connected, bool is_quoted, char quote_chr);

/* is_token_type.c */
int				is_tokentype_operator(t_token_type type);
int				is_tokentype_semicolon(t_token_type type);
int				is_tokentype_pipe_and_or(t_token_type type);
int				is_tokentype_redirection(t_token_type type);
int				is_tokentype_subshell(t_token_type type);

#endif //TOKENIZER_H
