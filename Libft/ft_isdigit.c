/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:22:22 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:41:13 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int	ft_isdigit(int c);

int	main(void)
{
	int i;

	i = 'A';
	printf("%d\n", ft_isdigit(i));
	printf("%d\n", isdigit(i));
	return (0);
}*/