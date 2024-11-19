/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcben335 <dcben335@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:45:17 by bcabocel          #+#    #+#             */
/*   Updated: 2024/11/19 00:47:13 by dcben335         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinbase(char *base, char c)
{
	while (*base)
		if (c == *(base++))
			return (1);
	return (0);
}

int	ft_atoi_base(const char *str, char *base)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isinbase(base, *str))
	{
		result = result * ft_strlen(base) + (ft_strchr(base, *str) - base);
		str++;
	}
	return (sign * result);
}
