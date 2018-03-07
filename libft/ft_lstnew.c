/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 10:31:03 by neprocur          #+#    #+#             */
/*   Updated: 2015/04/23 17:32:00 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;

	tmp = (t_list *)malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content = ft_memalloc(content_size);
		ft_strncpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
