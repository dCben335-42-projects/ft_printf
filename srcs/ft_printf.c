/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:20:49 by dcben335          #+#    #+#             */
/*   Updated: 2024/11/22 01:36:51 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	handle_map_print(
	const char *format,
	va_list ap,
	const t_conversion_map *map
)
{
	while (map->c)
	{
		if (*format == map->c)
			return (map->f(ap));
		map++;
	}
	return (0);
}

static int	ft_vprintf(
	const char *format,
	va_list ap,
	const t_conversion_map *map
)
{
	int	ret;
	int current_loop_ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format)) 
				current_loop_ret = handle_map_print(format, ap, map);
		}
		else
			current_loop_ret = ft_putchar_fd(*format, 1);
		if (current_loop_ret == -1)
			return (-1);
		ret += current_loop_ret;
		format++;
	}
	return (ret);
}

static const t_conversion_map	*ft_get_conversion_maps(void)
{
	static const t_conversion_map	conversion_maps[] = {
	{'c', &ft_print_char},
	{'s', &ft_print_string},
	{'p', &ft_print_pointer},
	{'d', &ft_print_int},
	{'i', &ft_print_int},
	{'u', &ft_print_unsigned_int},
	{'x', &ft_print_hex},
	{'X', &ft_print_hex_upper},
	{'%', &ft_print_percent},
	{0, NULL}};

	return (conversion_maps);
}

int	ft_printf(const char *format, ...)
{
	va_list					ap;
	int						ret;
	size_t					len;

	va_start(ap, format);
	if (!format)
		return (-1);
	len = ft_strlen(format);
	if (len == 0)
		return (0);
	if ((format[len - 1] == '%' && format[len - 2] != '%' && len > 1)
		|| (format[0] == '%' && len == 1))
		return (-1);
	ret = ft_vprintf(format, ap, ft_get_conversion_maps());
	va_end(ap);
	return (ret);
}
