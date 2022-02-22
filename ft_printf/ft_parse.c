/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:48:38 by vtyree            #+#    #+#             */
/*   Updated: 2021/11/29 18:24:26 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_type(char *format_string, va_list args)
{
	if (*format_string == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (*format_string == 's')
		return (ft_print_s(args));
	if (*format_string == 'd' || *format_string == 'i')
		return (ft_print_id(args));
	if (*format_string == 'u')
		return (ft_print_uxx(args, 2));
	if (*format_string == 'x')
		return (ft_print_uxx(args, 1));
	if (*format_string == 'X')
		return (ft_print_uxx(args, 0));
	if (*format_string == 'p')
		return (ft_print_p(args));
	if (*format_string == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	ft_parse_input(char *format_string, va_list args)
{
	int	length;
	int	n;

	length = 0;
	n = 0;
	while (*format_string)
	{
		if (*format_string != '%')
			length += ft_putchar_fd(*format_string, 1);
		else
		{
			if (*format_string++ == '\0')
			{
				ft_putchar_fd('\0', 0);
				return (length);
			}
			n = ft_parse_type(format_string, args);
			if (n < 0)
				break ;
			length += n;
		}
		format_string++;
	}
	return (length);
}
