/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:02:25 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 15:02:26 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# include "minishell.h"
# include <dirent.h>

/* ************************** */
/*          typedef           */
/* ************************** */
typedef struct s_env_elem		t_env_elem;
typedef struct s_export_info	t_export_info;
typedef struct s_cd_info		t_cd_info;
typedef enum e_key_type			t_key_type;

/* ************************** */
/*           enum             */
/* ************************** */

enum							e_cd_cmd_type
{
	e_home,
	e_absolute,
	e_relative,
	e_oldpwd,
	e_cdpath,
	e_opt_error,
	e_nomal,
	e_cd_init,
};

enum							e_key_type
{
	e_typeinit,
	e_append,
	e_error,
	e_add,
	e_novalue,
	e_nokey,
};

/* ************************** */
/*          struct            */
/* ************************** */
// ft_export
struct							s_export_info
{
	char						*key;
	char						*value;
	t_key_type					key_type;
};

// ft_cd
struct							s_cd_info
{
	int							cd_type;
	char						**home;
	char						**cdpath;
	char						**env_pwd;
	char						*pwd;
	char						**oldpwd;
	char						*newpwd;
	char						*cur_pwd;
};
/* ************************** */
/*         ft_builtin         */
/* ************************** */
int								ft_env(t_info *info, char **cmds);
int								ft_export(t_info *info, char **cmds);
int								ft_sort_env(t_info *info);
int								ft_unset(t_info *info, char **cmds);
int								ft_echo(char **cmds);
int								ft_pwd(t_info *info);
int								ft_cd(t_info *info, char **cmds);
int								ft_exit(t_info *info, char **cmds,
									bool in_pipe);
/* ************************** */
/*           helper           */
/* ************************** */
void							print_export_key_value(void *content);
int								perror_and_return_int(char *err,
									int exit_status);
char							**get_value_from_key(t_env_elem *elem,
									char *key);
char							**get_elem(t_info *info, char *key);
int								set_elem(t_info *info, char *key, char *value);
int								append_env(t_info *info, char *key,
									char *value);
int								add_env(t_info *info, char *key, char *value);
int								free_cdinfo_ret_status(t_cd_info *cd_info,
									int exit_status);
int								cd_error_handler(t_cd_info *cd_info,
									char **cmds);
void							init_key_value(t_export_info *e_info);
int								judge_chr_key(char *key);
t_key_type						judge_info_key(t_export_info *e_info);
t_key_type						judge_value(t_export_info *e_info);
int								judge_opt(char *cmd);
int								judge_cmd(char *cmd);
int								check_dir_exist(char *tdir, char *cmd,
									int print_flag);
void							ft_lst_ascsort(t_list **headRef);
int								chdir_setpath(t_info *info, t_cd_info *cd_info,
									char **cmds);
char							*define_new_path(t_cd_info *cd_info, char *cmd);

#endif //FT_BUILTIN_H
