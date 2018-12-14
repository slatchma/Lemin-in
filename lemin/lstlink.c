/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstlink.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/28 18:24:48 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/28 18:25:22 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static t_link	*ft_roomlink(t_link *roomlink, t_room *roomsave)
{
	t_link	*tmp;
	t_link	*maillon;

	maillon = (t_link*)malloc(sizeof(t_link));
	if (maillon == NULL)
		return (NULL);
	maillon->room = roomsave;
	maillon->next = NULL;
	if (roomlink == NULL)
		return (maillon);
	tmp = roomlink;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->room->name, roomsave->name) == 0)
			return (roomlink);
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->room->name, roomsave->name) == 0)
		return (roomlink);
	tmp->next = maillon;
	return (roomlink);
}

static void		ft_lsttest_one(t_room *tmp, t_room *roomtab[2], char **nameone,
				char **line)
{
	roomtab[0] = NULL;
	roomtab[1] = NULL;
	*nameone = ft_strndup(*line, '-');
	*line = *line + ft_strlen(*nameone) + 1;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, *nameone) == 0)
			roomtab[0] = tmp;
		if (ft_strcmp(tmp->name, *line) == 0)
			roomtab[1] = tmp;
		tmp = tmp->next;
	}
}

static int		ft_lsttest_two(t_room *roomtab[2], t_general *info, int nb)
{
	if (roomtab[0] == NULL || roomtab[1] == NULL)
		return (ft_write_error(info, 18, nb));
	return (0);
}

t_room			*ft_lstlink(t_room *listroom, char *line, t_general *info,
				int nb)
{
	t_room	*tmp;
	t_room	*roomtab[2];
	char	*nameone;

	tmp = listroom;
	nameone = NULL;
	ft_lsttest_one(tmp, roomtab, &nameone, &line);
	if (ft_lsttest_two(roomtab, info, nb) == -1)
		return (listroom);
	if (ft_strcmp(nameone, line) == 0)
		return (listroom);
	else
	{
		tmp = listroom;
		while (tmp != NULL)
		{
			if (ft_strcmp(tmp->name, nameone) == 0)
				tmp->roomlink = ft_roomlink(tmp->roomlink, roomtab[1]);
			if (ft_strcmp(tmp->name, line) == 0)
				tmp->roomlink = ft_roomlink(tmp->roomlink, roomtab[0]);
			tmp = tmp->next;
		}
	}
	free(nameone);
	return (listroom);
}
