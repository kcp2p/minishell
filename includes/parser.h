/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:02:53 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/* ************************** */
/*          typedef           */
/* ************************** */
typedef struct s_info			t_info;
typedef struct s_env_elem		t_env_elem;
typedef struct s_token_elem		t_token_elem;
typedef struct s_split_info		t_split_info;
typedef struct s_exec_list		t_exec_list;
typedef struct s_command_info	t_command_info;
typedef struct s_redirect_info	t_redirect_info;

typedef enum e_token_type		t_token_type;
typedef enum e_node_kind		t_node_kind;

/* ************************** */
/*         function           */
/* ************************** */
/* create_execlist_node.c */
t_exec_list		*create_execlist_node(t_node_kind kind, \
t_list_bi *token_lst, t_exec_list **prev, t_exec_list **next);

/* create_operator_list.c */
int				create_operator_list(\
t_list_bi **tokenlst_head, t_exec_list **execlst_head);
int				parsing_token_list(\
t_list_bi **tokenlist_head, t_exec_list **execlist_head, t_info *info);

/* create_operator_list_helper.c */
bool			is_pipeline_token(\
t_token_elem *token_elem, ssize_t	subshell_depth);
void			delete_operator_token(t_list_bi **operator_token);

/* create_command_list.c */
int				create_command_list(t_exec_list **exec_list_head);

/* create_redirect_list.c */
int				create_redirect_list(\
t_exec_list **exexlist_head, t_info *info);

/* create_redirect_list_helper;.c */
t_redirect_info	*create_redirect_info(\
t_token_type io_type, t_list_bi **token_list);

/* get_filename_or_heredoc_eof.c */
char			*get_filename_or_heredoc_eof(\
t_list_bi **token_get_frm, bool *quoted, bool is_expand, t_info *info);

/* move_tokens_to_cmd_info.c */
void			move_tokens_to_cmd_info(\
t_list_bi **tok_lst, t_command_info **cmd_lst, t_list_bi *popped_tok);
void			move_tokens_to_subshell_list(\
t_list_bi **tok_lst, t_command_info **cmd_lst, t_list_bi *popped_tok);
void			move_tokens_to_pipeline_list(\
t_command_info **command_list, t_list_bi *popped_token);

void			add_top_of_tree(t_exec_list **tree, t_exec_list *add_elem);
void			add_bottom_of_tree(t_exec_list **tree, t_exec_list *add_elem);
t_exec_list		*get_last_node(t_exec_list *node);
t_exec_list		*pop_from_top(t_exec_list **tree);
t_exec_list		*pop_from_bottom(t_exec_list **tree);

#endif //PARSER_H
