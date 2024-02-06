/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosorio- < cosorio-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:21:43 by cosorio-          #+#    #+#             */
/*   Updated: 2024/02/06 15:07:59 by cosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*placeholder;

	if (lst || new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			placeholder = *lst;
			while (placeholder->next != NULL)
				placeholder = placeholder->next;
			placeholder->next = new;
		}
	}
}
