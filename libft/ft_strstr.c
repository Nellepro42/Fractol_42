/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:01:55 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/09 20:27:28 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == 0)
		return ((char *)s1);
	else if (*s1 == 0)
		return (0);
	else if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
		return ((char *)s1);
	return (ft_strstr(s1 + 1, s2));
}
