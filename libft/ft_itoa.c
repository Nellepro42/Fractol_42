/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:57:08 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:27:18 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_digit(int n)
{
	int			i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	i++;
	return (i);
}

static char		*ft_create_string(int len, int n)
{
	char		*s;

	s = ft_strnew(len + 1);
	if (s != NULL)
	{
		len--;
		if (n < 0)
		{
			s[0] = '-';
			n = n * -1;
		}
		while (n / 10 > 0)
		{
			s[len] = (n % 10) + 48;
			len--;
			n /= 10;
		}
		s[len] = (n % 10) + 48;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*s;

	len = ft_nb_digit(n);
	if (n != -2147483648)
		s = ft_create_string(len, n);
	else
	{
		s = ft_strnew(12);
		if (s != NULL)
			ft_strcpy(s, "-2147483648");
	}
	return (s);
}
