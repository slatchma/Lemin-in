/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:42:36 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:42:38 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *arbre, const char *feuille, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (feuille[i] == '\0')
		return ((char *)arbre);
	while (arbre[i] != '\0' && i < n)
	{
		if (arbre[i] == feuille[0])
		{
			j = 0;
			while (arbre[i + j] == feuille[j] && i + j < n)
			{
				if (feuille[j + 1] == '\0')
					return ((char *)arbre + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
