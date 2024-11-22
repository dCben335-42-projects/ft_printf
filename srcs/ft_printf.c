/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:20:49 by dcben335          #+#    #+#             */
/*   Updated: 2024/11/22 06:38:18 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static const t_flag_map	*ft_get_flag_maps(void)
{
	static const t_flag_map	flag_maps[] = {
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

	return (flag_maps);
}

static int	handle_map_print(char *format, va_list ap, const t_flag_map *map)
{
	while (map->c)
	{
		if (*format == map->c)
			return (map->f(ap));
		map++;
	}
	return (ft_putstr_fd(--format, 2));
}

static size_t	ft_count_percent_at_end(const char *format)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_strlen(format);
	while (len > 0 && format[len - 1] == '%')
	{
		count++;
		len--;
	}
	return (count);
}

static int	ft_vprintf(	const char *format, va_list ap, const t_flag_map *map)
{
	int	ret;
	int	current_loop_ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format))
				current_loop_ret = handle_map_print((char *)format, ap, map);
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

int	ft_printf(const char *format, ...)
{
	va_list					ap;
	int						ret;

	va_start(ap, format);
	if (!format)
		ret = -1;
	else if (!*format)
		ret = 0;
	else if (ft_count_percent_at_end(format) % 2 == 1)
		ret = -1;
	else
		ret = ft_vprintf(format, ap, ft_get_flag_maps());
	va_end(ap);
	return (ret);
}
