/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstend.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:59:23 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 21:06:22 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_llist		*ft_lstend(t_llist *malist, int val)
{
	t_llist	*tmp;
	t_llist	*maillon;

	maillon = (t_llist*)malloc(sizeof(t_llist));
	if (maillon == NULL)
		return (NULL);
	maillon->var = val;
	maillon->next = NULL;
	if (malist == NULL)
		return (maillon);
	tmp = malist;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = maillon;
	return (malist);
}
