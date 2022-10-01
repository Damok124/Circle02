/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:11:56 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/02 01:00:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <sys/wait.h>

/////////////////////////
//	DEFINES
/////////////////////////
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define READ_END 0
# define WRITE_END 1
/////////////////////////
//	STRUCTURES
/////////////////////////
typedef struct s_data {
	int		ac;
	int		cursor;
	char	*infile;
	char	*outfile;
	char	**argv;
	char	**env;
	char	**paths;
	char	**cmd;
	char	**fullpaths;
	char	*validpath;
}			t_data;
/////////////////////////
//	PARSING
/////////////////////////
char	**ft_parse_cmd(char *arg);
char	**ft_get_paths(char **env);
char	**ft_get_fullpaths(char **paths, char *cmd);
char	*ft_get_validpath(t_data *data);
void	ft_get_next_cmd(t_data *data);
/////////////////////////
//	EXECUTION
/////////////////////////
void	ft_exec_cmd(char *validpath, char **cmd, char **env);
/////////////////////////
//	FD MANAGEMENT
/////////////////////////
void	ft_infile_to_stdin(t_data *data);
void	ft_outfile_to_stdout(t_data *data);
/////////////////////////
//	FREE
/////////////////////////
void	ft_free_data(t_data *data);

#endif
