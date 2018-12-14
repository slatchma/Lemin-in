/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_other.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 18:18:58 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/08 00:53:57 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	ft_waystep(t_way **lstway)
{
	t_way	*tmp;
	int		i;
	int		step;

	tmp = *lstway;
	step = 0;
	i = 0;
	while (tmp != NULL)
	{
		i = 0;
		step = 0;
		while (tmp->save[i] != '\0')
		{
			if (tmp->save[i] == '-')
				step++;
			i++;
		}
		tmp->step = step;
		tmp = tmp->next;
	}
}

int		ft_idem(t_room *roomstart, char *way)
{
	int		len;
	int		lenway;
	int		result;

	len = 0;
	lenway = ft_strlen(roomstart->name);
	result = -1;
	while (way[0] != '\0' && result == -1)
	{
		len = ft_strsupchr(way, '-');
		if (len == -1)
			len = ft_strlen(way);
		if (lenway == len)
		{
			if (ft_strnstr(way, roomstart->name, len) != NULL)
				result = 1;
			else
				result = -1;
		}
		if (result == -1 && ft_strsupchr(way, '-') != -1)
			way = way + len + 1;
		else
			way = way + len;
	}
	return (result);
}

int		ft_mintab(int compt, int step[compt])
{
	int mintab;
	int i;

	mintab = step[0];
	i = 0;
	while (i < compt)
	{
		if (step[i] < mintab)
			mintab = step[i];
		i++;
	}
	return (mintab);
}

int		ft_tcheck(t_dsplay *dway)
{
	t_dsplay	*tmp;
	int			result;

	result = 0;
	tmp = dway;
	while (tmp != NULL && result != 1)
	{
		if (tmp->ant > 0)
			result = 1;
		tmp = tmp->next;
	}
	return (result);
}

int		ft_verif(int compt, t_dsplay *dway[compt])
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < compt)
	{
		result = result + ft_tcheck(dway[i]);
		i++;
	}
	return (result);
}
