/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsearch.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:40:24 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 21:02:35 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_llist		*ft_lstsearch(t_llist *malist, int val)
{
	t_llist	*tmp;

	tmp = malist;
	while (tmp != NULL)
	{
		if (tmp->var == val)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
