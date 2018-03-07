/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:24:24 by neprocur          #+#    #+#             */
/*   Updated: 2014/11/13 11:42:40 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	char		*a;

	i = 0;
	a = (char *)malloc(sizeof(char) * (ft_strlen(s)));
	if (a == NULL)
		return (NULL);
	while (s[i])
	{
		a[i] = f(s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
