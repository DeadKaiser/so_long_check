/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:39:31 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:41:18 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	ft_isprint(int c);

int	main(void)
{
	int	i;

	i = 55;
	printf("%d\n", ft_isprint(i));
	printf("%d\n", isprint(i));
	return (0);
}
*/