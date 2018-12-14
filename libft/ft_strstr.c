/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:43:26 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:43:27 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *arbre, const char *feuille)
{
	size_t		len;
	size_t		i;

	if (*feuille == '\0')
		return ((char *)arbre);
	if (!feuille)
		return ((char *)arbre);
	len = ft_strlen(feuille);
	i = 0;
	while (arbre[i] != '\0')
	{
		if (ft_strncmp(arbre, feuille, len) == 0)
			return ((char *)arbre);
		arbre++;
	}
	return (NULL);
}
