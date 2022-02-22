/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:17:33 by vtyree            #+#    #+#             */
/*   Updated: 2021/10/21 17:55:48 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	ft_sign(int *n)
{
	int	sign;

	sign = 1;
	if (*n < 0)
	{
		sign = 0;
		*n *= -1;
	}
	return (sign);
}

char	*ft_itoa(int n)
{
	char			*out;
	size_t			len;
	unsigned int	n_ui;
	int				sign;

	len = ft_nbrlen(n);
	out = malloc(sizeof(char) * len + 1);
	if (out == NULL)
		return (NULL);
	sign = ft_sign(&n);
	n_ui = (unsigned int)n;
	out[len] = '\0';
	out[--len] = (n_ui % 10) + '0';
	n_ui /= 10;
	while (n_ui)
	{
		out[--len] = (n_ui % 10) + '0';
		n_ui /= 10;
	}
	if (sign == 0)
		out[0] = '-';
	return (out);
}
