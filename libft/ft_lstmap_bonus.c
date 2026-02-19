/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:32:38 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/08 19:10:08 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*h;
	t_list	*n;
	void	*c;

	if (!lst || !f || !del)
		return (NULL);
	h = NULL;
	while (lst)
	{
		c = f(lst->content);
		n = ft_lstnew(c);
		if (!n)
		{
			del(c);
			ft_lstclear(&h, del);
			break ;
		}
		ft_lstadd_back(&h, n);
		lst = lst->next;
	}
	return (h);
}
