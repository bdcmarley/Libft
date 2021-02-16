/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 11:46:16 by cmarley           #+#    #+#             */
/*   Updated: 2020/04/29 11:46:16 by cmarley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memblock, int cara, size_t size)
{
	int				i;
	unsigned char	c;
	unsigned char	*m;

	i = 0;
	c = (unsigned char)cara;
	m = (unsigned char *)memblock;
	while (size--)
	{
		if (m[i] == c)
			return (m + i);
		i++;
	}
	return (NULL);
}
