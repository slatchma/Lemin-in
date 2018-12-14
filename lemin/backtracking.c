/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_backtracking.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 17:46:58 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/28 17:56:48 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static t_way	*ft_lstway(t_way *lstway, char *way)
{
	t_way *tmp;
	t_way *maillon;

	maillon = (t_way*)malloc(sizeof(t_way));
	if (maillon == NULL)
		return (NULL);
	maillon->id = 1;
	maillon->step = 0;
	maillon->bestway = 0;
	maillon->save = ft_strdup(way);
	maillon->next = NULL;
	if (lstway == NULL)
		return (maillon);
	tmp = lstway;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = maillon;
	maillon->id = tmp->id + 1;
	return (lstway);
}

static char		*ft_writeway(t_room *roomstart, char *way)
{
	int n;
	int i;

	i = 0;
	n = ft_strlen(way);
	if (n != 0)
	{
		way[n] = '-';
		n++;
	}
	while (roomstart->name[i] != '\0')
	{
		way[n] = roomstart->name[i];
		n++;
		i++;
	}
	return (way);
}

static char		*ft_deleteway(char *way)
{
	int nb;

	nb = 0;
	nb = ft_strlen(way) - 1;
	if (nb < 0)
		nb = 0;
	while (way[nb] != '-' && nb > 0)
	{
		way[nb] = '\0';
		nb--;
	}
	way[nb] = '\0';
	return (way);
}

static char		*ft_solve(t_room *roomstart, char *way, t_way **lstway)
{
	t_link *tmplink;

	if (ft_idem(roomstart, way) == 1)
		return (way);
	else
		way = ft_writeway(roomstart, way);
	if (roomstart->end == 1)
	{
		*lstway = ft_lstway(*lstway, way);
		way = ft_deleteway(way);
		return (way);
	}
	tmplink = roomstart->roomlink;
	while (tmplink != NULL)
	{
		ft_solve(tmplink->room, way, lstway);
		tmplink = tmplink->next;
	}
	way = ft_deleteway(way);
	return (way);
}

t_way			*ft_backtracking(t_room *listroom, t_way *lstway,
				t_general *info)
{
	t_room	*roomstart;
	char	*way;

	way = NULL;
	way = ft_strnew(100);
	roomstart = ft_searchstart(listroom);
	way = ft_solve(roomstart, way, &lstway);
	if (lstway == NULL)
		ft_write_error(info, 22, 0);
	else
		ft_waystep(&lstway);
	free(way);
	return (lstway);
}
