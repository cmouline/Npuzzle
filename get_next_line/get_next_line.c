/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 10:56:11 by ecouderc          #+#    #+#             */
/*   Updated: 2015/01/26 20:05:36 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_split(char **s_line, int *ret)
{
	size_t	i;
	char	*tmp;
	char	*tmp_save;

	i = 0;
	while (*(*s_line + i) && *(*s_line + i) != '\n')
		i++;
	if (!(tmp = ft_strnew(i)))
		exit(1);
	ft_strncpy(tmp, *s_line, i);
	if ((*s_line)[i] == '\n' && (*ret = 1))
	{
		if (!(tmp_save = ft_strsub(*s_line, i + 1, \
						(ft_strlen(*s_line + i + 1)))))
			exit(1);
	}
	else
	{
		*ret = 2;
		if (!(tmp_save = ft_strnew(0)))
			exit(1);
	}
	free(*s_line);
	*s_line = tmp_save;
	return (tmp);
}

static int	ft_read(char **save_line, char **buf, const int fd, int *ret)
{
	char		*tmp;

	*ret = 0;
	while (((ft_strchr(*save_line, '\n')) == NULL)
			&& (*ret = read((int)fd, *buf, BUF_SIZE)) > 0)
	{
		(*buf)[*ret] = '\0';
		if (!(tmp = ft_strnew(ft_strlen(*save_line) + ft_strlen(*buf))))
			exit(1);
		ft_strcpy(tmp, *save_line);
		ft_strcat(tmp, *buf);
		free(*save_line);
		*save_line = tmp;
	}
	free(*buf);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*save_line;
	char		*buf;
	int			ret;

	if (!line)
		return (-1);
	if (!(buf = ft_strnew(BUF_SIZE)))
		exit(1);
	if (save_line == NULL && !(save_line = ft_strnew(0)))
		exit(1);
	if (!(*line))
		free(*line);
	if (!(*line = ft_strnew(0)))
		exit(1);
	if (read((int)fd, buf, 0) == -1)
		return (-1);
	ft_read(&save_line, &buf, fd, &ret);
	if (ft_strlen(*line) == 0 && ft_strlen(save_line) == 0 && ret == 0)
		return (0);
	free(*line);
	*line = ft_split(&save_line, &ret);
	return (ret);
}
