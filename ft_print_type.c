/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:56:23 by vtyree            #+#    #+#             */
/*   Updated: 2021/11/26 19:27:20 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_lowcase(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = str;
	while (*str)
	{
		if (ft_isalpha(*str))
		{
			*str = ft_tolower(*str);
		}
		str++;
	}
	return (ptr);
}

int	ft_print_s(va_list args)
{
	int		len;
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_putstr_fd(str, 1);
	return (len);
}

int	ft_print_id(va_list args)
{
	int			n;
	size_t		len;
	char		*nbr;

	n = va_arg(args, int);
	nbr = ft_itoa(n);
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}

int	ft_print_uxx(va_list args, char flag)
{
	uint64_t	n;
	size_t		len;
	char		*nbr;

	n = (uint64_t)va_arg(args, unsigned int);
	if (flag == 2)
		nbr = ft_itoa_base(n, 10);
	else if (flag == 0)
		nbr = ft_itoa_base(n, 16);
	else
	{
		nbr = ft_itoa_base(n, 16);
		nbr = ft_lowcase(nbr);
	}
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}

int	ft_print_p(va_list args)
{
	uint64_t	n;
	size_t		len;
	char		*addr;

	n = (uint64_t)va_arg(args, void *);
	addr = ft_itoa_base(n, 16);
	addr = ft_lowcase(addr);
	len = ft_putstr_fd("0x", 1) + ft_putstr_fd(addr, 1);
	free(addr);
	return (len);
}
