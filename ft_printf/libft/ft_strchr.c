/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:28:42 by vtyree            #+#    #+#             */
/*   Updated: 2021/10/20 19:15:04 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
