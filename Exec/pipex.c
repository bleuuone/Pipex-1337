/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbrahm <aelbrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:49:07 by aelbrahm          #+#    #+#             */
/*   Updated: 2023/01/19 00:03:53 by aelbrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		iter;

	iter = 2;
	if (ac == 5)
	{
		pipex.ab_path = get_path(env);
		pipex.infile = open(*(av + 1), O_RDWR, 0664);
		dup2(pipex.infile, STDIN_FILENO);
		pipex.outfile = open(*(av + ac - 1),
				O_CREAT | O_WRONLY | O_TRUNC, 0664);
		child(&pipex, env, *(av + iter));
		dup2(pipex.outfile, STDOUT_FILENO);
		command(*(av + ac - 2), env, &pipex);
	}
	err(MCMD);
}
