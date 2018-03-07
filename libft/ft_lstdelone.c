/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:12:03 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:54:23 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;

	if (alst == NULL)
		return ;
	list = *alst;
	del(list->content, list->content_size);
	free(list);
	*alst = NULL;
}
