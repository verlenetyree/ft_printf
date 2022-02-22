/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:29:00 by vtyree            #+#    #+#             */
/*   Updated: 2021/10/20 19:15:08 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1);
	copy = malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, len + 1);
	return (copy);
}
