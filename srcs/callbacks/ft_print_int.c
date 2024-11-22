/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:42:49 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/22 01:32:16 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print_int(va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	ft_putnbr_base_fd(n, "0123456789", 1);
	return (ft_putnbr_base_fd(n, "0123456789", 1));
}
