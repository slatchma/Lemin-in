/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:25:44 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:25:46 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *zone;

	zone = (void *)malloc(size);
	if (zone == NULL)
	{
		return (NULL);
	}
	ft_bzero(zone, size);
	return (zone);
}
