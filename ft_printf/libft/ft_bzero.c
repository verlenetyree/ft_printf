/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:14:39 by vtyree            #+#    #+#             */
/*   Updated: 2021/10/20 19:13:31 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*b;
	size_t	i;

	b = s;
	i = 0;
	while (i != n)
	{
		b[i++] = 0;
	}
	return ;
}
