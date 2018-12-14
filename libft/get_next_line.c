/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 15:24:43 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 16:47:15 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*ft_gnlnew(const int fd)
{
	t_gnl	*gnl;

	if (!(gnl = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	gnl->fd = fd;
	gnl->next = NULL;
	gnl->leftover = NULL;
	return (gnl);
}

static t_gnl	*ft_find_elem(t_gnl *gnl, int fd)
{
	t_gnl *tmp;

	tmp = gnl;
	while (tmp->fd != fd && tmp->next)
		tmp = tmp->next;
	if (!tmp->next && tmp->fd != fd)
	{
		tmp->next = ft_gnlnew(fd);
		tmp = tmp->next;
	}
	return (tmp);
}

static int		ft_newline(t_gnl **gnl, char **line)
{
	char		*str;

	if ((*gnl)->leftover && (str = ft_strchr((*gnl)->leftover, '\n')))
	{
		*str++ = '\0';
		if (!(*line = ft_strdup((*gnl)->leftover)))
			return (0);
		if (!(str = ft_strdup((*gnl)->leftover + (str - (*gnl)->leftover))))
			return (0);
		ft_strdel(&(*gnl)->leftover);
		if (*str)
			if (!((*gnl)->leftover = ft_strdup(str)))
				return (0);
		ft_strdel(&str);
		return (1);
	}
	return (0);
}

static int		ft_read(const int fd, t_gnl **gnl, int *ret, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if ((*gnl)->leftover && (ft_newline(gnl, line)))
		return (1);
	while ((*ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[*ret] = '\0';
		if ((*gnl)->leftover && (tmp = ft_strjoin((*gnl)->leftover, buff)))
		{
			ft_strdel(&(*gnl)->leftover);
			(*gnl)->leftover = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		else
			(*gnl)->leftover = ft_strdup(buff);
		if (ft_newline(gnl, line))
			return (1);
	}
	if ((*gnl)->leftover && (*line = ft_strdup((*gnl)->leftover)))
	{
		ft_strdel(&(*gnl)->leftover);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl		*gnl = NULL;
	t_gnl				*tmp;
	int					ret;
	char				*str;

	str = NULL;
	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, str, 0) == -1)
		return (-1);
	if (!gnl && !(gnl = ft_gnlnew(fd)))
		return (-1);
	tmp = ft_find_elem(gnl, fd);
	if (ft_read(fd, &tmp, &ret, line))
		return (1);
	return (0);
}
