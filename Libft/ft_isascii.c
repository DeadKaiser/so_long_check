/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:35:05 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:41:06 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	ft_isascii(int c);

int	main(void)
{
	int	i;

	i = 135;
	printf("%d\n", ft_isascii(i));
	printf("%d\n", isascii(i));
	return (0);
}*/