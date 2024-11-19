/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcabocel <bcabocel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 04:12:30 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/19 03:36:40 by bcabocel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_base(int n, int base_len)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

char	*ft_itoa_base(int n, char *base)
{
	unsigned int	nb;
	char			*str;
	int				len;
	int				base_len;

	base_len = ft_strlen(base);
	len = ft_intlen_base(n, base_len);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	nb = (unsigned int) n;
	if (n < 0)
	{
		str[0] = '-';
		nb = (unsigned int) -n;
	}
	while (--len >= 0)
	{
		str[len] = base[nb % base_len];
		nb /= base_len;
	}
	return (str);
}
