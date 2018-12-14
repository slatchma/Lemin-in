/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   initialize.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/08 00:48:00 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/08 00:48:27 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	ft_init_step(int **tab, t_way *lstway)
{
	int		i;
	t_way	*tmp;

	i = 0;
	while (tab[i][0] >= 0)
	{
		tmp = lstway;
		if (tab[i][0] == 0)
			tab[i][1] = -10;
		while (tmp != NULL)
		{
			if (tab[i][0] == tmp->id)
				tab[i][1] = tmp->step;
			tmp = tmp->next;
		}
		i++;
	}
}

void	ft_general_initialize(t_general *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	info->ants = 0;
	info->state = 0;
	info->phase = 0;
	info->signalstart = 0;
	info->signalend = 0;
	info->erroractiv = 0;
	info->warningactiv = 0;
	while (i < 30)
	{
		j = 0;
		while (j < 2)
		{
			info->error[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_room	*ft_searchstart(t_room *listroom)
{
	t_room *tmp;

	tmp = listroom;
	while (tmp != NULL)
	{
		if (tmp->start == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
