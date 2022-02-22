/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:59:20 by vtyree            #+#    #+#             */
/*   Updated: 2021/11/26 19:09:48 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* * * *
* The base is expressed as an unsigned integer, from 2 to 16.
* The characters comprising the base are the digits from 0 to 9,
* followed by uppercase letter from A to F.
*/

static int	ft_count_len(uint64_t n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*ft_itoa_base(uint64_t n, int base)
{
	char			*out;
	char			*str;
	int				len;

	if (base < 2 || base > 16)
		return (NULL);
	str = "0123456789ABCDEF";
	len = ft_count_len(n, base);
	out = malloc(sizeof(char) * len + 1);
	if (out == NULL)
		return (NULL);
	out[len] = '\0';
	if (n == 0)
		out[0] = '0';
	while (n)
	{
		out[--len] = *(str + (n % base));
		n /= base;
	}
	return (out);
}
