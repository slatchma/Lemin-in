/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wayunic.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 20:03:51 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/28 20:05:18 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static char	*ft_strway(int searchid, t_way *lstway)
{
	char	*str;
	t_way	*tmp;

	tmp = lstway;
	str = NULL;
	while (tmp != NULL)
	{
		if (searchid == tmp->id)
		{
			str = ft_strdup(tmp->save);
			return (str);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static int	ft_idemtwo(char *name, char *way)
{
	int		len;
	int		lenway;
	int		result;

	len = 0;
	lenway = ft_strlen(name);
	result = -1;
	while (way[0] != '\0' && result == -1)
	{
		len = ft_strsupchr(way, '-');
		if (len == -1)
			len = ft_strlen(way);
		if (lenway == len)
		{
			if (ft_strnstr(way, name, len) != NULL)
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

static void	ft_tmpfree(char **tmp)
{
	int l;

	l = 0;
	while (tmp[l] != NULL)
	{
		free(tmp[l]);
		tmp[l] = NULL;
		l++;
	}
	free(tmp);
	tmp = NULL;
}

static int	ft_wayunictwo(int **tab, t_way *lstway, char **tmp, int i_j[2])
{
	int		k;
	char	*idtmp;

	while (tab[i_j[1]][0] >= 0)
	{
		if (tab[i_j[1]][0] != 0)
		{
			k = 1;
			idtmp = ft_strway(tab[i_j[1]][0], lstway);
			while (tmp[k] != NULL && k < tab[i_j[0]][1])
			{
				if (ft_idemtwo(tmp[k], idtmp) == 1)
				{
					ft_strdel(&idtmp);
					return (1);
				}
				k++;
			}
			ft_strdel(&idtmp);
		}
		i_j[1]++;
	}
	return (0);
}

int			ft_wayunic(int **tab, t_way *lstway)
{
	char	*idtmp;
	char	**tmp;
	int		i_j[2];

	i_j[0] = 0;
	i_j[1] = 0;
	while (tab[i_j[0]][0] >= 0)
	{
		if (tab[i_j[0]][0] != 0)
		{
			i_j[1] = i_j[0] + 1;
			idtmp = ft_strway(tab[i_j[0]][0], lstway);
			tmp = ft_strsplit(idtmp, '-');
			ft_strdel(&idtmp);
			if (ft_wayunictwo(tab, lstway, tmp, i_j) == 1)
			{
				ft_tmpfree(tmp);
				return (1);
			}
			ft_tmpfree(tmp);
		}
		i_j[0]++;
	}
	return (0);
}
