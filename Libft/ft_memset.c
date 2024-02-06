/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:22:49 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:42:37 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
			i++;
	}
	return (b);
}

/*int	main(void)
{
	char	str[] = "jovanka";
	printf("%s\n", ft_memset(str, 'X', 5));
	printf("%s\n", memset(str, 'X', 5));
	return (0);
}*/