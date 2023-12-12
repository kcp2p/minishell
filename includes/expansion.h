/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:02:23 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

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

/* expansion.c */
int				expand_var_and_create_cmds_from_tokens(\
t_exec_list **pipeline_node, t_info *info);

/* expand_in_tokens.c */
char			*create_string_by_concat_tokens(t_list_bi *list_head);
int				expand_var_in_token_word(t_list_bi **src_tokens, t_info *info);

/* expand_in_heredoc.c */
int				do_expansion_in_heredoc(char *filename, t_info *info);

/* expand_in_filename.c */
int				expand_var_in_redirect_filename(\
t_command_info **cmd_list, t_info *info);

/* create_commands.c */
char			**create_expanded_commands(\
t_list_bi **token_list, t_info *info, char **concat_str);

/* concat_tokens_and_create_wildcard_valid_list.c */
int				concat_tokens_and_create_wildcard_valid_list(\
t_list_bi **token_list);
bool			check_valid_wildcard_in_word(t_token_elem *token);

/* get_expanded_str.c */
int				expand_var_in_str(char **src, t_info *info);
char			*concat_dst_to_src(char **dst, char *src);
/* get_env_value.c */
char			*get_name_str(const char *str_start_with_dollar);
char			*get_env_value(\
const char *search_key, t_list *env_list_head);

/* quote_removal_or_re_tokenize.c */
int				remove_quote_or_re_tokenize_tokens(t_list_bi **src_tokens);
int				remove_quote_in_tokens(t_list_bi **list_head);

int				re_tokenize_tokens(t_list_bi **src_tokens);

/* is_expand.c */
bool			is_expandable_var(const char *str, char quote_chr);
bool			is_name(const char *str);
bool			is_expandable_exit_status(const char *str);
bool			is_expandable_str_with_dollar(const char *str);

/* expand_wildcard.c */
int				expanded_wildcard_to_token_list(\
t_list_bi **expanded_token_list);
bool			is_not_expandable_command(t_list_bi *first_token);

/* concat_wildcard_valid_list.c */
int				concat_wildcard_valid_list(\
t_token_elem **dst, t_token_elem *src);

/* is_matches_wildcard.c */
int				is_matches_wildcard_and_target_str(const char *wildcard_str, \
const char *target_str, const int *valid_table);

/* get_dir_for_wildcard.c */
t_list_bi		*get_read_dir_list(void);

/* sort_strlist_for_wildcard.c */
void			sort_ascending_strlist(t_list_bi **list_head);

/* get_wildcard_tokens_from_dir */
int				get_wildcard_tokens(t_list_bi **get_tokens_save_to, \
const char *wildcard_str, const int *valid_list);

t_redirect_info	*create_redirect_info(\
t_token_type io_type, t_list_bi **tok_list);

#endif //EXPANSION_H
