/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 03:37:26 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/08 00:51:52 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_lstfree(t_room **listroom)
{
	t_room	*tmp;
	t_link	*tmplink;

	while (*listroom != NULL)
	{
		tmp = (*listroom)->next;
		while ((*listroom)->roomlink != NULL)
		{
			tmplink = (*listroom)->roomlink->next;
			free((*listroom)->roomlink);
			(*listroom)->roomlink = NULL;
			(*listroom)->roomlink = tmplink;
		}
		free((*listroom)->name);
		free(*listroom);
		*listroom = NULL;
		*listroom = tmp;
	}
}

static void	ft_wayfree(t_way **lstway)
{
	t_way *tmp;

	while (*lstway != NULL)
	{
		tmp = (*lstway)->next;
		free((*lstway)->save);
		(*lstway)->save = NULL;
		free(*lstway);
		*lstway = NULL;
		*lstway = tmp;
	}
}

int			ft_comptway(int *savecomb)
{
	int compt;
	int comptzero;

	compt = 0;
	comptzero = 0;
	while (savecomb[compt] >= 0)
	{
		if (savecomb[compt] == 0)
			comptzero++;
		compt++;
	}
	savecomb[compt - 1] = -1;
	return (compt - 1 - comptzero);
}

void		main_two(t_general *info, t_room *listroom, char *savetext)
{
	int		*savecomb;
	t_way	*lstway;
	int		compt;

	savecomb = NULL;
	lstway = NULL;
	lstway = ft_backtracking(listroom, lstway, info);
	if (info->error[22][0] == 0)
	{
		if (info->erroractiv == 1)
			info->warningactiv = 1;
		savecomb = ft_treatment(listroom, lstway, *info);
		ft_printf("%s\n", savetext);
		compt = ft_comptway(savecomb);
		ft_display(info->ants, savecomb, lstway, compt);
		free(savecomb);
		savecomb = NULL;
	}
	ft_wayfree(&lstway);
}

int			main(void)
{
	t_room		*listroom;
	t_general	info;
	char		*savetext;

	listroom = NULL;
	savetext = NULL;
	ft_general_initialize(&info);
	listroom = ft_lemin_parsing(listroom, &info, &savetext);
	if (info.phase == 2)
	{
		ft_lasttest(listroom, &info);
		if (info.error[5][0] == 0 && info.error[6][0] == 0 &&
				info.error[21][0] == 0 && info.error[26][0] == 0)
		{
			if (ft_particular(&info, listroom, savetext) == 0)
				main_two(&info, listroom, savetext);
		}
	}
	if (info.phase != 2 && info.erroractiv == 0)
		ft_write_error(&info, 2, 0);
	ft_error(info);
	ft_lstfree(&listroom);
	ft_strdel(&savetext);
	return (0);
}
