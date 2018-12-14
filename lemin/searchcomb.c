/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_searchcomb.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 18:27:51 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/08 00:54:57 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_tabduplicate(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i][0] >= 0)
	{
		j = i + 1;
		while (tab[j][0] >= 0)
		{
			if (tab[i][0] == tab[j][0] && tab[j][0] != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_maxtab(int **tab)
{
	int max;
	int i;

	max = tab[0][1];
	i = 0;
	while (tab[i][0] >= 0)
	{
		if (max < tab[i][1] && tab[i][0] != 0)
			max = tab[i][1];
		i++;
	}
	return (max);
}

void		ft_best_combtwo(int min, int **tab, int *tabsave)
{
	int maxtab;
	int i;

	maxtab = ft_maxtab(tab);
	if (tabsave[0] == -15 || maxtab < tabsave[min])
	{
		i = 0;
		while (i < min)
		{
			tabsave[i] = tab[i][0];
			i++;
		}
		tabsave[i] = maxtab;
	}
}

void		ft_best_comb(int min, int ants, int **tab, int *tabsave)
{
	int i;
	int *ptab;

	i = 0;
	ptab = NULL;
	while (ptab == NULL)
	{
		if (tab[i][0] != 0)
			ptab = &tab[i][1];
		else
			i++;
	}
	while (ants != 0)
	{
		i = 0;
		while (tab[i][0] >= 0)
		{
			if (tab[i][1] < *ptab && tab[i][0] != 0)
				ptab = &tab[i][1];
			i++;
		}
		*ptab = *ptab + 1;
		ants--;
	}
	ft_best_combtwo(min, tab, tabsave);
}

void		ft_searchcomb(int *tabsave, int **tab, int min_idmax_ants[3],
		t_way *lstway)
{
	int i;

	i = 0;
	while (tab[min_idmax_ants[0]][0] == -111)
	{
		i = 0;
		tab[i][0]++;
		while (i < min_idmax_ants[0])
		{
			if (tab[i][0] > min_idmax_ants[1])
			{
				tab[i][0] = 0;
				tab[i + 1][0]++;
			}
			i++;
		}
		if (ft_tabduplicate(tab) == 0 && tab[min_idmax_ants[0]][0] == -111)
		{
			ft_init_step(tab, lstway);
			if (ft_wayunic(tab, lstway) == 0)
				ft_best_comb(min_idmax_ants[0], min_idmax_ants[2], tab,
				tabsave);
		}
	}
}
