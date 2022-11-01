/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:11:56 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 22:46:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
/*
/////////////////////////
//	PARSING
/////////////////////////
void	ft_init_data(t_data *data, int ac, char **argv, char **env);
void	ft_init_data_b(t_data *data, int ac, char **argv, char **env);
char	**ft_parse_cmd(char *arg);
char	**ft_get_paths(char **env);
char	**ft_get_fullpaths(char **paths, char *cmd);
char	*ft_get_validpath(t_data *data);
char	*ft_get_validpath_b(t_data *data);
void	ft_get_next_cmd(t_data *data);
void	ft_get_next_cmd_b(t_data *data);
char	*ft_setup_limiter(const char *src, int *cursor);
char	*ft_get_tmpname(char **basename);
/////////////////////////
//	EXECUTION
/////////////////////////
void	ft_exec_cmd(char *validpath, char **cmd, char **env);
/////////////////////////
//	FD MANAGEMENT
/////////////////////////
void	ft_infile_to_stdin(t_data *data);
void	ft_infile_to_stdin_b(t_data *data);
void	ft_outfile_to_stdout(t_data *data);
void	ft_outfile_to_stdout_b(t_data *data);
void	ft_clean_connect(int std, int toconnect, int toclose);
/////////////////////////
//	ERROR
/////////////////////////
void	ft_cmd_not_found(char *str);
void	ft_err_msg(char *filename, char *str);
void	ft_print_error_msg(t_data *data);
/////////////////////////
//	FREE
/////////////////////////
void	ft_free_data(t_data *data);
*/
#endif
