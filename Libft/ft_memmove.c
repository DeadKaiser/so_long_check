/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:47:39 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:42:32 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "../include/so_long.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
	{
		while (len > i)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len -1] = ((char *)src)[len -1];
			len--;
		}
	}
	return (dst);
}

/*int	main(void)
{
	char	dest[100] = "aaaa";
	const char	src[100] = "123";
	size_t	n = 2;
	printf("%s", ft_memmove(dest, src, n));
}*/
