/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:44:16 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/19 05:47:17 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_upper(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	ft_putnbr_base_fd(n, "0123456789ABCDEF", 1);
	return (1);
}
