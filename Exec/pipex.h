/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbrahm <aelbrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:23:50 by aelbrahm          #+#    #+#             */
/*   Updated: 2023/01/19 00:04:19 by aelbrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"
/*=======================DEFINE'S SECTION=======================*/
# define KNRM	"\x1B[0m"
# define KRED	"\e[3m\x1B[31mCOMMAND NOT FOUND...\n"
# define RED	"\x1B[31m"
# define BLU	"\e[3m\e[1;34m"
# define HDC	"\x1B[31mSyntax Error: ./pipex here_doc \
limitter cmd1...cmdn file"
# define PERR	"\x1B[31mError: FAILURE IN PIPE"
# define FERR	"\x1B[31mError: FAILURE WHILE FORKING"
# define DIR1	"\x1B[31mError: Do not shit with ma \
shit=> no such file of directory\n"
# define DIR2	"\e[3m\x1B[31mError: No such file of directory\n"
# define PAT    "\e[3m\x1B[31mError: PATH env's variable unseted\n"
# define FD		"\e[3m\x1B[31mError: Couldn't open the file!\n"
# define MCMD	"\e[3m\x1B[31mSyntax Error: ./pipex file1 cmd1 cmd2 file2\n"
/*==================================================================*/
typedef struct s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		pid;
	char	*cmd_path;
	char	**ab_path;
	char	**cmd_arg;
}	t_pipex;

// => err_handling
//---------------------------------------------------------------------

void	deallocat(t_pipex *pipe);
void	cmd_path_err(char *cmd);
void	exev_err(char *err, t_pipex *pipe);
void	arg_err(char *str, t_pipex *pipex);
void	err(char *str);

//------------------------------------------------------------------------
// => PARSING
//------------------------------------------------------------------------

/// @brief retrieves the PATH from env variables
/// @param env 
/// @return The splited PATHS env's variable
char	**get_path(char **env);
/// @brief Checks the valide cmd path
/// @param path 
/// @param cmd 
/// @return The command path or NULL
char	*cmd_path(char **path, char *cmd);
int		cmd_check(char *cmd);

//----------------------------------------------------------------------
// => here_doc
//-----------------------------------------------------------------------

int		ft_strcmp(char *s1, char *s2);
void	compare(char *str_doc, char *arg, t_pipex *pipex);
void	here_doc(char *av, t_pipex *pipex, int *sid);

//------------------------------------------------------------------------
// => EXEC
//-------------------------------------------------------------------------

/// @brief Handels pipe between the parent and child proc
/// @param env 
/// @param pipe_st 
void	execution(char **env, t_pipex *pipe_st);
/// @brief Generate child's Process in order to exec cmd
/// @param pipex 
/// @param env 
/// @param av 
void	child(t_pipex *pipex, char **env, char *av);
/// @brief Handel the execution of last cmd
/// @param av 
/// @param env 
/// @param pipex 
/// @param sid 
void	command(char *av, char **env, t_pipex *pipex);

//-------------------------------------------------------------------------

#endif
