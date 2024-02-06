/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:06:55 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/05 23:44:29 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		if (s1 == NULL)
			return (0);
	}
	return (0);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	size_t	i;

// 	str1 = "bulbasaur";
// 	str2 = "bulba5aur";
// 	i = 8;
// 	printf("%d\n", ft_strncmp(str1, str2, i));
// 	printf("%d\n", strncmp(str1, str2, i));
// 	return (0);
// }