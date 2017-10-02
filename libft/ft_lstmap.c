/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:03:26 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 17:27:35 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_new;

	new = f(lst);
	if (new == NULL)
		return (NULL);
	begin_new = new;
	lst = lst->next;
	while (lst)
	{
		new->next = f(lst);
		if (new->next == NULL)
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (begin_new);
}
