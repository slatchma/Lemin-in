/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   link_parsing.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/28 17:29:16 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/28 17:29:18 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_linktest(t_general *info, char *line, int nb)
{
	if (ft_strlen(line) == 0)
		return (ft_write_error(info, 13, nb));
	if (line[0] == 'L')
		return (ft_write_error(info, 8, nb));
	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
			return (ft_write_error(info, 16, nb));
		if (ft_strcmp(line, "##end") == 0)
			return (ft_write_error(info, 17, nb));
		return (2);
	}
	if (ft_strsupchr(line, '-') == 0 || line[ft_strlen(line) - 1] == '-' ||
		line[0] == '-')
		return (ft_write_error(info, 12, nb));
	return (0);
}

int			ft_link(t_room **listroom, t_general *info, int nb, char *line)
{
	int i;
	int dash;
	int space;

	dash = 0;
	space = 0;
	if ((i = ft_linktest(info, line, nb)) == -1)
		return (-1);
	if (i == 2)
		return (2);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			dash++;
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (dash != 1 || space != 0)
		return (ft_write_error(info, 12, nb));
	*listroom = ft_lstlink(*listroom, line, info, nb);
	if (info->error[18][0] == 1)
		return (-1);
	return (2);
}
