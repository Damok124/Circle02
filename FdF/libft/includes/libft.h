/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:33:23 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/31 15:24:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <sys/stat.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_tools1 {
	char	*tmp;
	char	*line;
	int		n;
	int		i;
}			t_tools1;

typedef struct s_tools2 {
	char	*buff;
	char	*ret;
	int		count;
}			t_tools2;

/////////////////////////
//	PRINT
/////////////////////////
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_fd_itoa(int n, int fd);
void	ft_putnbr_base_fd(int nbr, char *base, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_show_tab_fd(int len, int *tab, int fd);
void	ft_show_strs_fd(char **strs, int fd);
/////////////////////////
//	FREE
/////////////////////////
void	ft_full_free(void **tobefree);
void	ft_true_free(void *ptr);
/////////////////////////
//	CHECK
/////////////////////////
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_check_dup_int(int len, int *tab);
size_t	ft_strlen(const char *str);
/////////////////////////
//	INITIALIZATION
/////////////////////////
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/////////////////////////
//	TRANSFORMATION
/////////////////////////
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_atoi_safe(const char *nptr, int *check);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		*ft_strs_to_tab(int len, char **strs);
/////////////////////////
//	RESEARCH
/////////////////////////
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
/////////////////////////
//	COPY
/////////////////////////
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		*ft_tabdup(int len, int *src, int *dest);
char	*get_next_line(int fd);
/////////////////////////
//	SORTING
/////////////////////////
int		*ft_sort_int_tab(int *tab, int size);
/////////////////////////
//	LISTS
/////////////////////////
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lst_find_one(t_list *lst, int position);
void	ft_index_intlist(t_list **astack, int *sortedav, int ac);
void	ft_memset_lst(t_list **list, void *content);
t_list	*ft_tab_to_lst(int ac, int *tab);
void	ft_full_free_lst(t_list **list);

#endif
