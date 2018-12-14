/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:26:53 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:26:56 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;
	size_t				i;

	i = 0;
	tmp1 = s1;
	tmp2 = s2;
	if (n == 0)
	{
		return (0);
	}
	while (i < (n - 1) && tmp1[i] == tmp2[i])
	{
		i++;
	}
	return (tmp1[i] - tmp2[i]);
}
