/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:46:03 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:45:00 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*int	ft_toupper(int c);

int	main(void)
{
	int	i;

	i = 'Z';
	printf("%d\n", ft_toupper(i));
	printf("%d\n", toupper(i));
	return (0);
}
*/