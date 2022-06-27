/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_42_1337.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:07:22 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/10 07:52:27 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_42_1337_H
# define PIPEX_42_1337_H
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include <fcntl.h>
# include <string.h>
# include<sys/wait.h>

typedef struct t_fd
{
	int		std_in;
	int		std_out;
	int		to_close;
	int		argc;
	char	**env;
	char	**argv;
}	t_fd;

char	*path_chec(char **engvic, char **env);
void	error_print(char **engvic);
int		chec_slash(char *ptr);
char	*access_func(char **str);
void	close_pipe(int *fd);
int		chec_slash(char *ptr);
void	failed_function(char *path, char **engvic);
char	**ft_split(char const *s, char c);
char	*get_path(char **env, char *cmd);
int		get_index_of_path(char **env);
void	pipex_42(int argv, char **argc, char **env, int file);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *src);
int		check_fun(char *s);
int		check_back_s(char *s);
char	*d_line(char *line);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_function(char **str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
int		check_fun(char *s);
int		check_back_s(char *s);
char	*d_line(char *line);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif