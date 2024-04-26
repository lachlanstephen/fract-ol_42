/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:26:03 by lstephen          #+#    #+#             */
/*   Updated: 2023/08/19 20:17:50 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_del(const char *str, char c)
{
	size_t	i;
	char	*skipped;

	i = 0;
	skipped = (char *)str;
	while (skipped[i] != 0 && skipped[i] == c)
		skipped = &skipped[i + 1];
	return (&skipped[0]);
}

static size_t	word_count(const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = i + 1;
	count = 1;
	if (str[i] == 0)
	{
		return (0);
	}
	while (str[j] != 0)
	{
		if (str[j] == c && str[j - 1] != c)
		{
			count++;
		}
		j++;
	}
	if (str[j - 1] == c)
		count--;
	return (count);
}

static size_t	word_length(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != 0 && str[len] != c)
		len++;
	return (len);
}

static char	*allocate_word(const char *str, char c, size_t i, char **arr)
{
	size_t	len;
	size_t	j;
	char	*new_str;

	len = word_length(str, c);
	j = 0;
	arr[i] = malloc(sizeof(char) * len + 1);
	if (arr[i] == NULL)
	{
		while (j < i)
			free(arr[j++]);
		free(arr);
		return (NULL);
	}
	while (j < len)
	{
		arr[i][j] = str[j];
		j++;
	}
	arr[i][j] = '\0';
	new_str = skip_del(&str[j], c);
	j = 0;
	return (&new_str[0]);
}

char	**ft_split(const char *str, char c)
{
	size_t	word_amnt;
	size_t	i;
	char	**arr;

	str = skip_del(str, c);
	word_amnt = word_count(str, c);
	i = 0;
	arr = malloc(sizeof(char *) * (word_amnt + 1));
	if (arr == NULL)
		return (NULL);
	while (i < word_amnt)
	{
		str = allocate_word(str, c, i, arr);
		if (str == NULL)
		{
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
