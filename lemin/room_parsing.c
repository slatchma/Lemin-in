/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   room_parsing.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/28 14:45:43 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/28 14:47:02 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_dash(t_general *info, char *line, int nb)
{
	int i;
	int space;

	i = 0;
	space = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			space++;
		if (space == 0 && line[i] == '-')
			return (ft_write_error(info, 7, nb));
		if (space != 0 && line[i] == '-')
			return (ft_write_error(info, 15, nb));
		i++;
	}
	return (-1);
}

static void	ft_check_room_init(int *i, int *nbspace, int *dash, char *line)
{
	*i = 0;
	*nbspace = 0;
	*dash = 0;
	while (line[*i] != '\0')
	{
		if (line[*i] == ' ')
			*nbspace = *nbspace + 1;
		if (line[*i] == '-')
			*dash = *dash + 1;
		*i = *i + 1;
	}
}

static int	ft_check_room(t_general *info, char *line, int nb)
{
	int i;
	int nbspace;
	int dash;

	ft_check_room_init(&i, &nbspace, &dash, line);
	if (nbspace == 0 && dash == 1)
		return (2);
	if (nbspace != 2 || line[i - 1] == ' ')
		return (ft_write_error(info, 12, nb));
	i = ft_strsupchr(line, ' ');
	if (line[i + 1] == ' ')
		return (ft_write_error(info, 12, nb));
	if (dash != 0)
		return (ft_dash(info, line, nb));
	while (line[i] != '\0')
	{
		if (!((line[i] >= 48 && line[i] <= 57) || line[i] == ' '))
			return (ft_write_error(info, 12, nb));
		i++;
	}
	return (1);
}

static int	ft_room_two(t_general *info, char *line, int nb)
{
	if (ft_strlen(line) == 0)
		return (ft_write_error(info, 13, nb));
	if (line[0] == 'L')
		return (ft_write_error(info, 8, nb));
	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
			info->signalstart++;
		else if (ft_strcmp(line, "##end") == 0)
			info->signalend++;
		return (1);
	}
	return (100);
}

int			ft_room(t_room **listroom, t_general *info, int nb, char *line)
{
	int i;
	int result;

	i = 0;
	if ((result = ft_room_two(info, line, nb)) != 100)
		return (result);
	if (info->signalstart > 10)
		return (ft_write_error(info, 19, nb - 1));
	if (info->signalend > 10)
		return (ft_write_error(info, 20, nb - 1));
	result = ft_check_room(info, line, nb);
	if (result == 1)
	{
		*listroom = ft_lstroom(*listroom, line, info, nb);
		if (info->error[3][0] == 1 || info->error[9][0] == 1 ||
			info->error[10][0] == 1)
			return (-1);
		return (1);
	}
	return (result);
}
