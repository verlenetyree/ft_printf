/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:24:14 by vtyree            #+#    #+#             */
/*   Updated: 2021/10/20 19:14:01 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*sc;

	sc = s;
	i = -1;
	while (++i < n)
	{
		if (*sc++ == (char)c)
			return ((void *)s + i);
	}
	return (NULL);
}
