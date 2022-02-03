/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:03:02 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

typedef struct d_arg
{
	struct d_arg	*next;
	struct d_arg	*prev;
	char			*path;
	char			**args;
	char			*content;
}	t_arg;

t_arg	*ft_lst2_new(char *content);
void	ft_lst2add_back(t_arg **lst, t_arg *new);
int		ft_is_space(char c);
void	ft_show_lst(t_arg *lst);
void	ft_free_lst(t_arg **lst);
int		ft_closed_quote(char *arg_str);
int		ft_next_other(char *arg_str);
int		ft_next_space_pipe(char *arg_str);
int		ft_pull(char *args_str, char **cur_arg, int n);
void	ft_remove_quotes(void *content);
void	ft_remove_quotes_func(t_arg *func_l);
void	ft_replace_by_envp(char **content, char**envp);
void	ft_handle_envps(t_arg *arg_l, char**envp);
int		ft_is_pipe_or_redir(void *cont);
char	*ft_strjoin2(char **s1, char *s2);
void	ft_lst2add_args(t_arg **lst, char **line);
char	**ft_add_args(char **old_arr, char *new_elem);
void	ft_args_control(t_arg **arg_l, char ***arr);
void	free_all(char **result);
void	free_all_exclude_head(char **result);
void	ft_set_funcs_structure(t_arg *arg_l, t_arg **func_l);
void	ft_set_func_args(t_arg **arg_l, t_arg **func_l);
void	ft_parse_input_str(char *args_str, t_arg **arg_l);
char	*ft_return_env(char **envp, char *var);
int		ft_set_path(t_arg *func_l, char *path, char ***envp);
void	ft_set_heredoc(t_arg *func_l);
int		ft_arr_len(char **array);
char	**ft_char_array_cpy(char **array);
int		ft_correct_number(char *number);
int		ft_is_valid_dollar(char *content);
char	*ft_find_path(void *content, char *path);
void	ft_check_eof(char *args_str, char **env_array);
int		ft_check_syntax_errors(t_arg *func_l);
void	ft_read_history(int history_fd);
void	ft_write_history(int history_fd, char *line, int argc, char **argv);
void	ft_free_argl_func_l_argstr(t_arg **arg_l,
			t_arg **func_l, char *args_str);

void	nothing(int signal);
void	sig_int_par(int signal);
void	ft_sig_parent(void);
void	ft_sig_child(void);
void	ft_sig_par_ignore(void);
void	sig_quit_par(int signal);
void	sig_quit_ch(int signal);
void	ft_sig_child_heredoc(void);
void	ft_sig_ignore(void);
/*evgenii's*/
void	ft_exec(t_arg *lst, char ***argv);
void	ft_pwd(char **argc, char ***envp);
void	ft_cd(char **argc, char ***envp);
void	ft_echo(char **argv, char ***envp);
void	ft_exit(char **argv, char ***envp);
void	(*ft_find_buildin(char **argc, char **envp))(char **argc, char ***envp);
void	ft_env(char **argc, char ***env_array);
void	ft_export(char **args, char ***env_array);
void	ft_unset(char **args, char ***env_array);
void	ft_call_export(char **argc, char ***envp, int status);
t_arg	*ft_find_heredoc(t_arg *lst);
t_arg	*ft_find_redirect(t_arg *lst);
char	**ft_binding_args(char **args_first, char **args_second, int flag);
void	show_args(char **args);
void	ft_free(char **array);
int		ft_array_cpm(char **args_first, char **args_second);
int		ft_is_built_int(char *func_name);
t_arg	*ft_find_command(t_arg *lst, char ***envp);
int		ft_is_a_command(t_arg *lst);
t_arg	*ft_find_heredoc(t_arg *lst);
t_arg	*ft_find_redirect(t_arg *lst);
void	ft_redirect(t_arg *redirect, char *file, char **envp);
char	**ft_redirect_in_command(t_arg *lst, char ***envp);
char	**ft_redirect_in_file(t_arg *lst, char ***envp);
void	ft_add(char *file_name);
void	ft_rewrite(char *file_name);
void	ft_heredoc(t_arg *heredoc, char *stop, char **envp);
t_arg	*ft_find_output(t_arg *lst);
int		ft_find_output_int(t_arg *lst);
t_arg	*ft_find_pipe(t_arg *lst);
int		ft_find_pipe_int(t_arg *lst);
int		ft_lstcmp(t_arg *lst);
void	ft_heredoc(t_arg *heredoc, char *stop, char **envp);
void	ft_pipe(char *path, char **argc, char ***envp);
void	ft_return(char *path, char **argc, char ***envp);
void	ft_return_one_command(char *path, char **argv, char ***envp);
void	signal_handler_in_exec(int status, char **argv, char ***envp);
void	ft_exit(char **argv, char ***envp);
void	ft_echo(char **argv, char ***envp);
void	ft_cd(char **argc, char ***envp);
void	ft_pwd(char **argc, char ***envp);
int		count_argv(char **argv);
void	ft_set_oldpwd(char *old_pwd, char ***envp);
void	ft_set_pwd(char ***envp);

#endif
