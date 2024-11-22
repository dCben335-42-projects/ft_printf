/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:45:00 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/22 06:00:25 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_putull_base_fd(
	unsigned long long nb,
	char *base,
	size_t base_len,
	int fd
)
{
	int	len;
	int	current_loop_ret;

	len = 0;
	if (nb >= base_len)
	{
		current_loop_ret = ft_putull_base_fd(nb / base_len, base, base_len, fd);
		if (current_loop_ret == -1)
			return (-1);
		len += current_loop_ret;
	}
	if (ft_putchar_fd(base[nb % base_len], fd) == -1)
		return (-1);
	return (len + 1);
}
