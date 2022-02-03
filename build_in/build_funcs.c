/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:38:03 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 14:16:56 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_argv(char **argv)
{
	int		size;
	char	**save;

	save = argv;
	size = 0;
	while (save[size])
		size++;
	return (size);
}

void	(*ft_find_buildin(char **argc, char **envp))(char **argc, char ***envp)
{
	char	*func_name;
	void	(*buildin)(char **argc, char ***envp);

	func_name = argc[0];
	buildin = NULL;
	(void)envp;
	if (!ft_strncmp(func_name, "pwd", 4))
		buildin = ft_pwd;
	if (!ft_strncmp(func_name, "cd", 3))
		buildin = ft_cd;
	if (!ft_strncmp(func_name, "echo", 5))
		buildin = ft_echo;
	if (!ft_strncmp(func_name, "unset", 6))
		buildin = ft_unset;
	if (!ft_strncmp(func_name, "export", 7))
		buildin = ft_export;
	if (!ft_strncmp(func_name, "env", 4))
		buildin = ft_env;
	if (!ft_strncmp(func_name, "exit", 5))
		buildin = ft_exit;
	return (buildin);
}

void	ft_call_export(char **argc, char ***envp, int status)
{
	char	*export[3];
	char	*error;

	(void)argc;
	error = ft_itoa(status);
	export[0] = "export";
	export[1] = ft_strjoin("?=", error);
	export[2] = NULL;
	ft_export(export, envp);
	free(error);
	free(export[1]);
}
