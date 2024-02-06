/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:36:23 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:44:10 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	b = 0;
	c = 0;
	while (dst[a] != '\0' && a < size)
		a++;
	while (src[b] != '\0' && a + b + 1 < size)
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a < size)
		dst[a + b] = '\0';
	while (src[c] != '\0')
		c++;
	return (a + c);
}
