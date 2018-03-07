/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:15:43 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:52:49 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	if (lst != NULL && *f)
	{
		new_list = (*f)(lst);
		if (new_list && lst->next)
			new_list->next = ft_lstmap(lst->next, f);
		return (new_list);
	}
	return (NULL);
}
