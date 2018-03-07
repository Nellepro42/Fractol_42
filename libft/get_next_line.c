/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:13:02 by neprocur          #+#    #+#             */
/*   Updated: 2015/03/05 16:18:12 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_save_str(char **buf, char *str, int ret)
{
	char			*ptr;

	str[ret] = '\0';
	ptr = *buf;
	*buf = ft_strjoin(*buf, str);
	ft_strdel(&ptr);
}

int					get_next_line(int const fd, char **line)
{
	int				ret;
	static char		*buf[256];
	char			*ptr;
	char			*str;
	int				len;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || !(str = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	buf[fd] = !buf[fd] ? ft_strnew(1) : buf[fd];
	while (!(ft_strchr(buf[fd], 0x0a)) && (ret = read(fd, str, BUFF_SIZE)) > 0)
		ft_save_str(&buf[fd], str, ret);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !(ft_strchr(buf[fd], 0x0a)))
	{
		*line = buf[fd];
		buf[fd] = NULL;
		return (((*line)[0] == '\0') ? 0 : 1);
	}
	len = ft_strchr(buf[fd], 0x0a) - buf[fd];
	*line = ft_strsub(buf[fd], 0, len);
	ptr = buf[fd];
	buf[fd] = ft_strdup(ft_strchr(buf[fd], 0x0a) + 1);
	ft_strdel(&ptr);
	return (1);
}
