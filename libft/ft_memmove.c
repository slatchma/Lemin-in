/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:29:45 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:29:48 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmpd;

	tmpd = (void *)malloc(n * sizeof(void *));
	if (tmpd == NULL)
		return (NULL);
	ft_memcpy(tmpd, src, n);
	ft_memcpy(dest, tmpd, n);
	free(tmpd);
	return (dest);
}
