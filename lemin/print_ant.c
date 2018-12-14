/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_ant.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/31 12:08:41 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/08 00:56:17 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

t_dsplay		*ft_ant_next(t_dsplay *dway)
{
	t_dsplay	*tmp;
	int			anttmp;
	int			ant;

	tmp = dway;
	ant = 0;
	anttmp = 0;
	while (tmp != NULL)
	{
		anttmp = tmp->ant;
		tmp->ant = ant;
		ant = anttmp;
		tmp = tmp->next;
	}
	return (dway);
}

static void		ft_print_two(t_dsplay *dway)
{
	t_dsplay	*tmp;

	tmp = dway;
	while (tmp != NULL)
	{
		if (tmp->ant != 0)
			ft_printf("L%d-%s ", tmp->ant, tmp->name);
		tmp = tmp->next;
	}
}

static void		ft_print(int compt, t_dsplay *dway[compt])
{
	int i;

	i = 0;
	while (i < compt)
	{
		ft_print_two(dway[i]);
		i++;
	}
}

static void		ft_print_finish(int compt, t_dsplay *dway[compt])
{
	int i;
	int result;

	result = ft_verif(compt, dway);
	while (result != 0)
	{
		i = 0;
		while (i < compt)
		{
			dway[i] = ft_ant_next(dway[i]);
			i++;
		}
		ft_print(compt, dway);
		result = ft_verif(compt, dway);
		if (result != 0)
			ft_printf("\n");
	}
}

void			ft_print_ant(int compt, t_dsplay *dway[compt],
				int step[compt], int ants)
{
	int i;
	int nameant;
	int mintab;

	nameant = 1;
	mintab = 0;
	while (nameant <= ants)
	{
		ft_print_ant_two(compt, dway);
		mintab = ft_mintab(compt, step);
		i = 0;
		while (i < compt)
		{
			if (step[i] == mintab && nameant <= ants)
			{
				step[i]++;
				dway[i]->ant = nameant;
				nameant++;
			}
			i++;
		}
		ft_print(compt, dway);
		ft_printf("\n");
	}
	ft_print_finish(compt, dway);
}
