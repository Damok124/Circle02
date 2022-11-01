/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:11:56 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 19:49:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <sys/wait.h>
# include <sys/types.h>
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
}			t_data;
/////////////////////////
//	PARSING
/////////////////////////
char	**ft_get_paths(char **env);
char	**ft_parse_cmd(char *arg);
void	ft_clean_connect(int std, int toconnect, int toclose);
void	ft_cmd_not_found(char *str);
int		ft_such_file(char *filename);
int		ft_infile_permission(char *filename);
int		ft_outfile_permission(char *filename);
void	ft_close_stdfds(void);
void	ft_double_fullfree(char **strs1, char **strs2);
void	ft_infile_to_in(char **argv, char **cmd_args, char **validpaths, int i);
char	*ft_get_goodpath(char **cmd, char **fullpaths);
char	**ft_get_fullpaths(char **paths, char *cmd);
char	**ft_get_validpaths(int ac, char **argv, char **paths);
void	ft_outfile_to_out(char **paths, int i, char **cmd_a, t_data *data);
void	ft_pipex(t_data *data, char **validpaths);
int		ft_test_files(char **argv, int ac);
void	ft_print_cmderr(char **validpaths, char **argv);
t_data	ft_init_data(int ac, char **argv, char **env);
/*
char	**ft_parse_cmd(char *arg);
void	ft_init_data(t_data *data, int ac, char **argv, char **env);
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
//	ERROR
/////////////////////////
void	ft_cmd_not_found(char *str);
void	ft_err_msg(char *filename, char *str);
int		ft_print_error_msg(t_data *data);
/////////////////////////
//	FREE
/////////////////////////
void	ft_free_data(t_data *data);
*/
#endif
