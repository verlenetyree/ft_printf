/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:31:32 by vtyree            #+#    #+#             */
/*   Updated: 2021/10/20 19:15:28 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*uc1;
	const unsigned char	*uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	while (n--)
	{
		if (*uc1 != *uc2++)
			return (*uc1 - *--uc2);
		if (*uc1++ == 0)
			return (0);
	}
	return (0);
}
