/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_with_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:37:05 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 18:05:45 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pipe_logic(int *pip, char *path, char **argc, char ***envp)
{
	void	(*buildin)(char **argc, char ***envp);

	buildin = ft_find_buildin(argc, *envp);
	ft_sig_child();
	close(pip[0]);
	dup2(pip[1], 1);
	close(pip[1]);
	if (buildin)
		buildin(argc, envp);
	else if (path)
		execve(path, argc, *envp);
	else
		ft_call_export(argc, envp, 127);
	exit(0);
}

void	ft_pipe(char *path, char **argc, char ***envp)
{
	int		pid;
	int		pip[2];

	pipe(pip);
	pid = fork();
	if (!pid)
		ft_pipe_logic(pip, path, argc, envp);
	else
	{
		ft_sig_par_ignore();
		close(pip[1]);
		dup2(pip[0], 0);
		close(pip[0]);
	}
}

void	ft_return(char *path, char **argc, char ***envp)
{
	int		pid;
	int		pip[2];
	void	(*buildin)(char **argc, char ***envp);

	buildin = ft_find_buildin(argc, *envp);
	pipe(pip);
	pid = fork();
	if (!pid)
	{
		ft_sig_child();
		if (buildin)
			buildin(argc, envp);
		else
			execve(path, argc, *envp);
		exit(0);
	}
	else
	{
		ft_sig_par_ignore();
		close(pip[1]);
		dup2(pip[0], 0);
		close(pip[0]);
		waitpid(pid, NULL, 0);
	}
}

void	ft_return_one_command(char *path, char **argv, char ***envp)
{
	int		pid;
	void	(*buildin)(char **argc, char ***envp);
	int		status;

	errno = 0;
	buildin = ft_find_buildin(argv, *envp);
	if (buildin)
		buildin(argv, envp);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			ft_sig_child();
			execve(path, argv, *envp);
			exit (1);
		}
		else
		{
			ft_sig_par_ignore();
			waitpid(0, &status, 0);
			signal_handler_in_exec(status, argv, envp);
		}
	}
}
