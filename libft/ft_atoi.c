/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:34:18 by neprocur          #+#    #+#             */
/*   Updated: 2015/04/22 17:25:04 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;
	char	*s;

	i = 0;
	sign = 1;
	result = 0;
	s = (char *)str;
	while (ft_isspace(s[i]) == 1)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]) == 1)
	{
		result = (s[i] - 48) + result * 10;
		i++;
	}
	return (result * sign);
}
