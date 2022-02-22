/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:13:24 by vtyree            #+#    #+#             */
/*   Updated: 2021/11/24 20:47:50 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		length;
	char	*format_string;
	va_list	args;

	length = 0;
	va_start(args, format);
	format_string = (char *)format;
	length = ft_parse_input(format_string, args);
	va_end(args);
	return (length);
}
