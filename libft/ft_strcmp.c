/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:45:09 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/11 16:54:09 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (0);
	else if (*s1 == *s2)
		return (ft_strcmp(s1 + 1, s2 + 1));
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
