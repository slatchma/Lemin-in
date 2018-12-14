/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnsearch.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:58:07 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 20:50:59 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_llist		*ft_lstnsearch(t_llist *malist, size_t n)
{
	t_llist	*tmp;
	size_t	i;

	tmp = malist;
	i = 0;
	while (tmp->next != NULL && i < n)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == n)
		return (tmp);
	return (NULL);
}
