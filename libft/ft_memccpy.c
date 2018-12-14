/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:25:57 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:26:00 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmpd;
	unsigned char	*tmps;

	i = 0;
	tmpd = (unsigned char *)dest;
	tmps = (unsigned char *)src;
	while (i < n)
	{
		tmpd[i] = tmps[i];
		if (tmps[i] == (unsigned char)c)
			return ((void *)&tmpd[i + 1]);
		i++;
	}
	return (NULL);
}
