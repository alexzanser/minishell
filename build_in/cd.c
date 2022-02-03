/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:15:57 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 14:16:56 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char **argc, char ***envp)
{
	char	*old_pwd;
	int		i;

	i = -1;
	(void)envp;
	if (chdir(argc[1]) == -1)
	{
		ft_putstr_fd("minishell$: ", 2);
		perror(argc[1]);
		ft_call_export(argc, envp, 1);
		return ;
	}
	else
	{
		while ((*envp)[++i])
		{
			if (!ft_strncmp((*envp)[i], "PWD", 3) && (ft_strlen((*envp)[i])
				- ft_strlen(ft_strchr((*envp)[i], '=')) == 3))
				old_pwd = ft_strdup(ft_strchr((*envp)[i], '=') + 1);
		}
		ft_set_oldpwd(old_pwd, envp);
		ft_set_pwd(envp);
		ft_call_export(argc, envp, 0);
	}
}
