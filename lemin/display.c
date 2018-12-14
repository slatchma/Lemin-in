/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/30 23:42:17 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 12:04:42 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static t_dsplay	*ft_lstway(t_dsplay *way, char *save)
{
	t_dsplay *tmp;
	t_dsplay *maillon;

	maillon = (t_dsplay*)malloc(sizeof(t_dsplay));
	if (maillon == NULL)
		return (NULL);
	maillon->name = ft_strndup(save, '-');
	maillon->ant = 0;
	maillon->next = NULL;
	if (way == NULL)
		return (maillon);
	tmp = way;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = maillon;
	return (way);
}

static t_dsplay	*ft_write_way(t_dsplay *way, char *save)
{
	int i;

	i = 0;
	save = save + ft_strsupchr(save, '-') + 1;
	while (i >= 0)
	{
		way = ft_lstway(way, save);
		i = ft_strsupchr(save, '-');
		save = save + i + 1;
	}
	return (way);
}

static t_dsplay	*ft_create_way(t_dsplay *way, t_way *lstway, int idsearch,
				int *step)
{
	t_way *tmp;

	tmp = lstway;
	while (tmp != NULL)
	{
		if (idsearch == tmp->id)
		{
			way = ft_write_way(way, tmp->save);
			*step = tmp->step;
		}
		tmp = tmp->next;
	}
	return (way);
}

void			ft_dwayfree(t_dsplay **dway)
{
	t_dsplay *tmp;

	tmp = *dway;
	while (tmp != NULL)
	{
		(*dway) = tmp;
		free((*dway)->name);
		(*dway)->name = NULL;
		tmp = (*dway)->next;
		free((*dway));
		(*dway = NULL);
	}
}

void			ft_display(int ants, int *savecomb, t_way *lstway, int compt)
{
	int			i;
	int			j;
	int			step[compt];
	t_dsplay	*dway[compt];

	i = 0;
	j = 0;
	while (savecomb[i] >= 0)
	{
		if (savecomb[i] > 0)
		{
			dway[j] = NULL;
			dway[j] = ft_create_way(dway[j], lstway, savecomb[i], &step[j]);
			j++;
		}
		i++;
	}
	ft_print_ant(compt, dway, step, ants);
	i = 0;
	while (i < compt)
	{
		ft_dwayfree(&dway[i]);
		i++;
	}
}
