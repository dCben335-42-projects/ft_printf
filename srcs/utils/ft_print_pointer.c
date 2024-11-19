/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:41:53 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/19 05:50:25 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_nbr_base(
	unsigned long long nb,
	char *base,
	unsigned int base_len,
	int fd
)
{
	if (nb >= base_len)
		write_nbr_base(nb / base_len, base, base_len, fd);
	ft_putchar_fd(base[nb % base_len], fd);
}

static void	ft_putptr_fd(unsigned long long nb, char *base, int fd)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return ;
	write_nbr_base(nb, base, base_len, fd);
}

int	ft_print_pointer(va_list ap)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	ft_putstr_fd("0x", 1);
	ft_putptr_fd((unsigned long long)ptr, "0123456789abcdef", 1);
	return (1);
}
