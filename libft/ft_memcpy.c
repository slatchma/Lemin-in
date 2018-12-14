/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:29:11 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:29:13 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmpd;
	const unsigned char	*tmps;

	i = 0;
	tmpd = dest;
	tmps = src;
	while (i < n)
	{
		tmpd[i] = tmps[i];
		i++;
	}
	return (dest);
}
