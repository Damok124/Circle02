/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:11:56 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/17 01:19:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <sys/wait.h>
# include <stdio.h>

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
	char	**argv;
	char	**env;
	char	**paths;
	char	**fullpaths;
	char	*validpath;
	char	*infile;
	char	*outfile;
	char	**cmd;
	int		cursor;
}			t_data;
/////////////////////////
//	PARSING
/////////////////////////
char	**ft_parse_cmd(char *arg);
char	**ft_get_paths(char **env);
char	**ft_get_fullpaths(char **paths, char *cmd);
char	*ft_get_validpath(t_data *data);
void	ft_get_next_cmd(t_data *data);
char	*ft_setup_limiter(const char *src);
char	*ft_get_tmpname(char *basename);
/////////////////////////
//	EXECUTION
/////////////////////////
void	ft_exec_cmd(char *validpath, char **cmd, char **env);
/////////////////////////
//	FD MANAGEMENT
/////////////////////////
void	ft_infile_to_stdin(t_data *data);
void	ft_outfile_to_stdout(t_data *data);
void	ft_clean_connect(int std, int toconnect, int toclose);
/////////////////////////
//	FREE
/////////////////////////
void	ft_free_data(t_data *data);

#endif
