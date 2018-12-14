/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:35:01 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:35:03 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t n;

	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
