/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:39:08 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:39:09 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		tmp[i] = f(s[i]);
		i++;
	}
	return (tmp);
}
