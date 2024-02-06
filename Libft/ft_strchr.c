/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:18:16 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:43:37 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	j;
	unsigned int	i;

	j = (unsigned char)c;
	i = 0;
	while (s[i] != '\0' && s[i] != j)
		i++;
	if (s[i] == j)
		return ((char *)s + i);
	return (0);
}

/*int	main(void)
{
	const char	*str;
	int			i;

	str = "bulbasaur";
	i = 's';
	printf("%s\n", ft_strchr(str, i));
	printf("%s\n", strchr(str, i));
	return (0);
}
*/