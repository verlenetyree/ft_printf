/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:28:44 by vtyree            #+#    #+#             */
/*   Updated: 2021/11/26 19:27:45 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

// PARSER
int		ft_parse_type(char *format_string, va_list args);
int		ft_parse_input(char *format_string, va_list args);
int		ft_print_s(va_list args);
int		ft_print_id(va_list args);
int		ft_print_uxx(va_list args, char flag);
int		ft_print_p(va_list args);

#endif
