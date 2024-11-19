/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:34:18 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/19 05:45:43 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

# include <stdio.h>

typedef struct s_conversion_map
{
	char	c;
	int		(*f)(va_list);
}	t_conversion_map;

int		ft_printf(const char *format, ...);

int		ft_print_char(va_list ap);
int		ft_print_string(va_list ap);
int		ft_print_pointer(va_list ap);
int		ft_print_int(va_list ap);
int		ft_print_int(va_list ap);
int		ft_print_unsigned_int(va_list ap);
int		ft_print_hex(va_list ap);
int		ft_print_hex_upper(va_list ap);
int		ft_print_percent(va_list ap);

#endif	