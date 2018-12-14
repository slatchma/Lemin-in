/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treatment.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 18:28:50 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/28 18:54:55 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_mincomb(t_general info, t_room *listroom)
{
	int		min;
	int		i;
	t_room	*tmp;
	t_link	*tmplink;

	min = info.ants;
	tmp = listroom;
	tmplink = NULL;
	while (tmp != NULL)
	{
		if (tmp->start == 1 || tmp->end == 1)
		{
			tmplink = tmp->roomlink;
			i = 0;
			while (tmplink != NULL)
			{
				i++;
				tmplink = tmplink->next;
			}
			if (i < min)
				min = i;
		}
		tmp = tmp->next;
	}
	return (min);
}

static int	ft_idmax(t_way *lstway)
{
	int		i;
	t_way	*tmp;

	tmp = lstway;
	i = 0;
	while (tmp != NULL)
	{
		i = tmp->id;
		tmp = tmp->next;
	}
	return (i);
}

static int	**ft_tab_init(int **tab, int min, int *tabsave)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < min)
	{
		j = 0;
		while (j < 2)
		{
			tab[i][j] = 0;
			j++;
		}
		tabsave[i] = -15;
		i++;
	}
	tab[i][0] = -111;
	tab[i][1] = -222;
	tabsave[i] = -15;
	tabsave[i + 1] = -777;
	return (tab);
}

static void	ft_treatmentfree(int **tab, int min_idmax_ants[3])
{
	int i;

	i = 0;
	while (i < min_idmax_ants[0] + 1)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int			*ft_treatment(t_room *listroom, t_way *lstway, t_general info)
{
	int min_idmax_ants[3];
	int	**tab;
	int *tabsave;

	tab = NULL;
	min_idmax_ants[0] = ft_mincomb(info, listroom);
	min_idmax_ants[1] = 0;
	min_idmax_ants[2] = info.ants;
	if (!(tab = (int**)malloc(sizeof(int*) * (min_idmax_ants[0] + 1))))
		return (NULL);
	if (!(tabsave = (int*)malloc(sizeof(int) * (min_idmax_ants[0] + 2))))
		return (NULL);
	while (min_idmax_ants[1] <= min_idmax_ants[0])
	{
		if (!(tab[min_idmax_ants[1]] = (int*)malloc(sizeof(int) * 2)))
			return (NULL);
		min_idmax_ants[1]++;
	}
	tab = ft_tab_init(tab, min_idmax_ants[0], tabsave);
	min_idmax_ants[1] = ft_idmax(lstway);
	ft_searchcomb(tabsave, tab, min_idmax_ants, lstway);
	ft_treatmentfree(tab, min_idmax_ants);
	return (tabsave);
}
