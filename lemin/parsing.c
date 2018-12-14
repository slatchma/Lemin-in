/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/28 14:03:17 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/28 14:27:53 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_ants(char *line, t_general *info)
{
	int i;

	i = 0;
	if (ft_strlen(line) == 0)
		return (ft_write_error(info, 13, 1));
	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
			return (ft_write_error(info, 23, 1));
		else if (ft_strcmp(line, "##end") == 0)
			return (ft_write_error(info, 24, 1));
		return (0);
	}
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0)
			return (ft_write_error(info, 0, 1));
		i++;
	}
	info->ants = ft_atoi(line);
	if (info->ants < 0)
		return (ft_write_error(info, 3, 1));
	if (info->ants == 0)
		return (ft_write_error(info, 25, 1));
	return (1);
}

static char	*ft_savetext(char **savetext, char *line)
{
	char *tmpfree;

	if (*savetext == NULL)
	{
		*savetext = (char*)malloc(sizeof(char) * 1);
		if (*savetext == NULL)
			return (NULL);
		*savetext[0] = '\0';
	}
	tmpfree = *savetext;
	*savetext = ft_strjoin(*savetext, line);
	free(tmpfree);
	tmpfree = NULL;
	tmpfree = *savetext;
	*savetext = ft_strjoin(*savetext, "\n");
	free(tmpfree);
	tmpfree = NULL;
	return (NULL);
}

int			ft_lasttest(t_room *listroom, t_general *info)
{
	t_room	*tmp;
	int		start;
	int		end;

	start = 0;
	end = 0;
	tmp = listroom;
	while (tmp != NULL)
	{
		if (tmp->start == 1)
			start++;
		if (tmp->end == 1)
			end++;
		if (tmp->start == 1 && tmp->end == 1)
			return (ft_write_error(info, 26, 0));
		tmp = tmp->next;
	}
	if (start == 0)
		return (ft_write_error(info, 5, 0));
	if (end == 0)
		return (ft_write_error(info, 6, 0));
	if (start > 1 || end > 1)
		return (ft_write_error(info, 21, 0));
	return (1);
}

t_room		*ft_lemin_parsing(t_room *listroom, t_general *info,
			char **savetext)
{
	char	*line;
	int		nb;

	line = NULL;
	nb = 0;
	while (get_next_line(0, &line) == 1 && info->state != -1)
	{
		nb++;
		if (info->state == 1)
			info->state = ft_room(&listroom, info, nb, line);
		if (info->state == 2)
			info->phase = 2;
		if (info->state == 2)
			info->state = ft_link(&listroom, info, nb, line);
		if (info->state == 0)
			info->state = ft_ants(line, info);
		if (info->state != -1)
			ft_savetext(savetext, line);
		ft_strdel(&line);
	}
	if (line != NULL)
		ft_strdel(&line);
	if (info->state == 0)
		ft_write_error(info, 4, 1);
	return (listroom);
}
