/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:32:26 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/06 16:46:43 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;
	t_list	*x;

	if (!lst || !del)
		return ;
	t = *lst;
	while (t)
	{
		x = t->next;
		del(t->content);
		free(t);
		t = x;
	}
	*lst = NULL;
}
