/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:39:28 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:39:29 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	lengt;
	size_t	i;
	char	*tmp;

	if (!s)
		return (NULL);
	lengt = ft_strlen((char *)s);
	tmp = (char *)malloc(sizeof(char) * (lengt + 1));
	if (tmp == NULL)
	{
		return (NULL);
	}
	tmp[lengt] = '\0';
	i = 0;
	while (i < lengt)
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	return (tmp);
}
