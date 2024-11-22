/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:41:53 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/22 01:32:40 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print_pointer(va_list ap)
{
	void	*ptr;
	int		ret;

	ptr = va_arg(ap, void *);
	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	ret = ft_putull_base_fd((size_t) ptr, "0123456789abcdef", 16, 1);
	if (ret == -1)
		return (-1);
	return (ret + 2);
}
