/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:43:13 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 19:05:49 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_compt(char const *s, char c)
{
	int		i;
	int		compt;
	int		mot;

	i = 0;
	compt = 0;
	mot = 0;
	while (s[i] != '\0')
	{
		if (mot == 0 && s[i] != c)
		{
			mot = 1;
			compt++;
		}
		else if (mot == 1 && s[i] == c)
		{
			mot = 0;
		}
		i++;
	}
	return (compt);
}

static size_t	ft_taillelimit(char const *s, char c, int *j)
{
	size_t	len;

	len = 0;
	while (s[*j] != c && s[*j] != '\0')
	{
		len++;
		*j = *j + 1;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nbremot;
	char	**philip;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nbremot = ft_compt(s, c);
	philip = (char **)malloc(sizeof(char *) * (nbremot + 1));
	if (philip == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (i < nbremot)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		philip[i] = ft_strsub(s, j, ft_taillelimit(s, c, &j));
		if (philip[i] == NULL)
			return (NULL);
		i++;
	}
	philip[i] = NULL;
	return (philip);
}
