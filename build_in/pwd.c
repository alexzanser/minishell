/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:17:59 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/21 13:53:11 by kmercy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_oldpwd(char *old_pwd, char ***envp)
{
	int		i;
	char	*tmp;

	i = -1;
	while ((*envp)[++i])
	{
		if (!ft_strncmp((*envp)[i], "OLDPWD", 6) && (ft_strlen((*envp)[i])
			- ft_strlen(ft_strchr((*envp)[i], '=')) == 6))
		{
			tmp = (*envp)[i];
			(*envp)[i] = ft_strjoin("OLDPWD=", old_pwd);
		}
	}
	if (old_pwd)
		free(old_pwd);
	if (tmp)
		free(tmp);
}

void	ft_set_pwd(char ***envp)
{
	int		i;
	char	dir[200];
	char	*tmp;

	i = -1;
	while ((*envp)[++i])
	{
		if (!ft_strncmp((*envp)[i], "PWD", 3) && (ft_strlen((*envp)[i])
			- ft_strlen(ft_strchr((*envp)[i], '=')) == 3))
		{
			tmp = (*envp)[i];
			getcwd(dir, 200);
			(*envp)[i] = ft_strjoin("PWD=", dir);
			free(tmp);
		}
	}
}

void	ft_pwd(char **argc, char ***envp)
{
	char	dir[200];

	(void)argc;
	(void)envp;
	if (getcwd(dir, 200) != NULL)
	{
		write(1, dir, ft_strlen(dir));
		write(1, "\n", 1);
	}
	ft_call_export(argc, envp, 0);
}
