/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 21:48:23 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 21:01:13 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*str;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	while ((ft_isblank(s[i]) == 1) && (s[i]))
		i++;
	str = ft_strdup(s + i);
	i = ft_strlen(str) - 1;
	while ((ft_isblank(str[i]) == 1) && (i >= 0))
		i--;
	str[i + 1] = '\0';
	return (str);
}
