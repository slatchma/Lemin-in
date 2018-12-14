/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 01:33:52 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 01:34:56 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int c)
{
	char	*dup;
	int		i;
	int		j;

	j = ft_strsupchr(src, c);
	if (j == -1)
		j = ft_strlen(src);
	dup = (char*)malloc(sizeof(char) * (j + 1));
	if (dup == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0' && i <= j)
	{
		dup[i] = src[i];
		i++;
	}
	dup[j] = '\0';
	return (dup);
}
