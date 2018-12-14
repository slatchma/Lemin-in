/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:26:18 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 19:34:26 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *tmps;
	size_t				i;

	i = 0;
	tmps = s;
	while (i < n)
	{
		if (tmps[i] == (unsigned char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
