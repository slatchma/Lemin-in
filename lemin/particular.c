/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   particular.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/08 00:52:30 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/08 01:07:04 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_particular_test(t_room *listroom, char **end)
{
	t_room *tmp;
	t_link *tmplink;

	tmp = listroom;
	while (tmp != NULL)
	{
		if (tmp->start == 1)
		{
			tmplink = tmp->roomlink;
			while (tmplink != NULL)
			{
				if (tmplink->room->end == 1)
				{
					*end = tmplink->room->name;
					return (1);
				}
				tmplink = tmplink->next;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int			ft_particular(t_general *info, t_room *listroom, char *savetext)
{
	int		result;
	int		i;
	char	*end;

	result = 0;
	i = 1;
	end = NULL;
	if (ft_particular_test(listroom, &end) == 1)
	{
		result = 1;
		if (info->erroractiv == 1)
			info->warningactiv = 1;
		ft_printf("%s\n", savetext);
		while (i <= info->ants)
		{
			ft_printf("L%d-%s ", i, end);
			i++;
		}
		ft_printf("\n");
	}
	return (result);
}

void		ft_print_ant_two(int compt, t_dsplay *dway[compt])
{
	int i;

	i = 0;
	while (i < compt)
	{
		dway[i] = ft_ant_next(dway[i]);
		i++;
	}
}
