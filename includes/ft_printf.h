/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:34:18 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/22 01:32:21 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_conversion_map
{
	char	c;
	int		(*f)(va_list);
}	t_conversion_map;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);

// put
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_base_fd(int nb, char *base, int fd);
int		ft_putull_base_fd(size_t nb, char *base, size_t base_len, int fd);

// put (callbacks)
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