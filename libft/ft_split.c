/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:28:33 by vtyree            #+#    #+#             */
/*   Updated: 2021/10/20 19:14:59 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_strs_count(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			n++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

static char	*ft_fill_array(char const *s, char c)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	ptr = (char *)(malloc(sizeof(char) * (i + 1)));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = ft_strs_count(s, c);
	out = (char **)malloc(sizeof(char *) * (n + 1));
	if (!s || !out)
		return (NULL);
	out[n] = NULL;
	while (i < n)
	{
		while (s[j] == c && s[j])
			j++;
		out[i] = (char *)(s + j++);
		while (s[j] != c && s[j])
			j++;
		out[i] = ft_fill_array(out[i], c);
		if (!out[i++])
			ft_free_array(out);
	}
	return (out);
}
