/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:30:24 by vtyree            #+#    #+#             */
/*   Updated: 2021/10/20 19:15:17 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	len;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	len = dlen;
	if (dstsize < dlen)
		return (dstsize + slen);
	while (*src && len + 1 < dstsize)
	{
		dst[len++] = *src++;
	}
	if (len < dstsize)
		dst[len] = '\0';
	return (dlen + slen);
}
