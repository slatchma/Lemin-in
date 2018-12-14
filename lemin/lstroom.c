/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstroom.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/28 17:07:44 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/28 17:08:42 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_nbre_len(int nbre)
{
	int i;

	i = 1;
	while (nbre > 0)
	{
		nbre = nbre / 10;
		i++;
	}
	return (i);
}

static void	ft_maillon_init(t_room *maillon, t_general *info, char *line)
{
	maillon->name = ft_strndup(line, ' ');
	while (line[0] != ' ' && line[0] != '\0')
	{
		line++;
	}
	line++;
	maillon->next = NULL;
	maillon->start = 0;
	maillon->end = 0;
	maillon->roomlink = NULL;
	if (info->signalstart == 1)
	{
		maillon->start = 1;
		info->signalstart = 10;
	}
	if (info->signalend == 1)
	{
		maillon->end = 1;
		info->signalend = 10;
	}
	maillon->coord[0] = -5;
	maillon->coord[1] = -5;
	maillon->coord[0] = ft_atoi(line);
	maillon->coord[1] = ft_atoi(line + ft_nbre_len(maillon->coord[0]));
}

static int	ft_lsttest(t_room *tmp, t_room *maillon, t_general *info, int nb)
{
	int	stop;

	stop = 0;
	while (stop != 1)
	{
		if (ft_strcmp(tmp->name, maillon->name) == 0 && tmp->coord[0] ==
			maillon->coord[0] && tmp->coord[1] == maillon->coord[1])
			return (1);
		if (ft_strcmp(tmp->name, maillon->name) == 0 && (tmp->coord[0] !=
			maillon->coord[0] || tmp->coord[1] != maillon->coord[1]))
			return (ft_write_error(info, 9, nb));
		if (ft_strcmp(tmp->name, maillon->name) != 0 && tmp->coord[0] ==
			maillon->coord[0] && tmp->coord[1] == maillon->coord[1])
			return (ft_write_error(info, 10, nb));
		if (tmp->next == NULL)
			stop = 1;
		else
			tmp = tmp->next;
	}
	tmp->next = maillon;
	return (0);
}

t_room		*ft_lstroom(t_room *listroom, char *line, t_general *info, int nb)
{
	t_room	*tmp;
	t_room	*maillon;
	int		result;

	if ((maillon = (t_room*)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	ft_maillon_init(maillon, info, line);
	if (maillon->coord[0] < 0 || maillon->coord[1] < 0)
	{
		ft_write_error(info, 3, nb);
		free(maillon);
		return (listroom);
	}
	if (listroom == NULL)
		return (maillon);
	tmp = listroom;
	if ((result = ft_lsttest(tmp, maillon, info, nb)) == 1)
		return (listroom);
	if (result == -1)
	{
		free(maillon->name);
		free(maillon);
		return (listroom);
	}
	return (listroom);
}
