/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:00:57 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/19 05:34:49 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_nbr_base(
	unsigned int nb,
	char *base,
	unsigned int base_len,
	int fd
)
{
	if (nb >= base_len)
		write_nbr_base(nb / base_len, base, base_len, fd);
	ft_putchar_fd(base[nb % base_len], fd);
}

void	ft_putnbr_base_fd(int nb, char *base, int fd)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return ;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	write_nbr_base((unsigned int)nb, base, base_len, fd);
}
