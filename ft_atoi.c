/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:29:19 by cmarley           #+#    #+#             */
/*   Updated: 2020/02/11 08:29:22 by cmarley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		index;
	int		neg;
	long	res;

	index = 0;
	res = 0;
	while (str[index] == 32 || (str[index] > 8 && str[index] < 14))
		index++;
	neg = (str[index] == '-') ? 1 : 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (ft_isdigit(str[index]) && res < 2147483649)
	{
		res = (res * 10) + (str[index] - '0');
		index++;
	}
	if ((neg && res > 2147483648) || (!neg && res > 2147483647))
		return (neg ? 0 : -1);
	return ((int)(neg ? -res : res));
}
