/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:57:31 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/18 06:33:39 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *str1, const char *str2, size_t n);
char		*ft_strdup(const char *str);
char		*ft_substr(const char *str, unsigned int start, size_t len);
char		*ft_strjoin(const char *str1, const char *str2);
char		*ft_strtrim(const char *str, const char *set);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *str, char (*f)(unsigned int, char));

char		**ft_split(const char *str, char c);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
int			ft_atoi(const char *str);

size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t		ft_strlcat(char *dest, const char *src, size_t destsize);

void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_calloc(size_t amnt, size_t size);
void		ft_striteri(char *str, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);

// Bonus Functions

int			ft_lstsize(t_list *lst);

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

// ft_printf Functions

int			ft_printf(const char *str, ...);
int			ft_printf_char(int c);
int			ft_printf_str(char *str);
int			ft_printf_int(int num);
int			ft_printf_ptr(void *ptr);
int			ft_printf_unsigned(unsigned int num);
int			ft_printf_hex(unsigned int num, char type);

#endif
