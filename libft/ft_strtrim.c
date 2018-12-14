/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:44:04 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 19:06:56 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_start(char *philip)
{
	int		i;

	i = 0;
	while (philip[i] == ' ' || philip[i] == '\n' || philip[i] == '\t')
		i++;
	return (philip + i);
}

static size_t	ft_size(char *philip)
{
	size_t		taille;

	taille = ft_strlen(philip);
	if (taille == 0)
		return (taille);
	while (philip[taille] == ' ' || philip[taille] == '\t' ||
			philip[taille] == '\n' || philip[taille] == '\0')
		taille--;
	return (taille + 1);
}

char			*ft_strtrim(char const *s)
{
	char		*philip;
	char		*result;
	size_t		taille;

	if (!s)
		return (NULL);
	philip = (char *)s;
	taille = 0;
	if (*philip != '\0')
	{
		philip = ft_start(philip);
		taille = ft_size(philip);
	}
	result = (char *)malloc(sizeof(char) * (taille + 1));
	if (result == NULL)
		return (NULL);
	result = ft_strncpy(result, philip, taille);
	result[taille] = '\0';
	return (result);
}
