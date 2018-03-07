/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:13:25 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:54:36 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*l_tmp;

	if (alst == NULL)
		return ;
	l_tmp = *alst;
	while (l_tmp->next)
	{
		del(l_tmp->content, l_tmp->content_size);
		l_tmp = l_tmp->next;
	}
	del(l_tmp->content, l_tmp->content_size);
	free(l_tmp);
	*alst = NULL;
}
