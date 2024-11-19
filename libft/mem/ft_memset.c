/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcben335 <dcben335@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:38:25 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/19 00:45:22 by dcben335         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "stdlib.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	chr;

	tmp = (unsigned char *) s;
	chr = (unsigned char) c;
	while (n--)
		*(tmp++) = chr;
	return (s);
}
