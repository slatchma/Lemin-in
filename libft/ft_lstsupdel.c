/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsupfirst.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:10:04 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 12:02:53 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_llist		*ft_delfirst(t_llist *malist)
{
	t_llist *tmp;

	if (malist != NULL)
	{
		tmp = malist;
		tmp = tmp->next;
		free(malist);
		return (tmp);
	}
	return (NULL);
}

t_llist		*ft_delend(t_llist *malist)
{
	t_llist *tmpone;
	t_llist	*tmptwo;

	if (malist == NULL)
	{
		return (NULL);
	}
	if (malist->next == NULL)
	{
		free(malist);
		return (NULL);
	}
	tmpone = malist;
	tmptwo = malist;
	while (tmpone->next != NULL)
	{
		tmptwo = tmpone;
		tmpone = tmpone->next;
	}
	tmptwo->next = NULL;
	free(tmpone);
	return (malist);
}

t_llist		*ft_lstsupdel(t_llist *malist, int n)
{
	t_llist	*tmpone;
	t_llist	*tmptwo;
	t_llist	*tmpfree;
	int		i;

	if (n == 0)
		return (ft_delfirst(malist));
	if (n == -1)
		return (ft_delend(malist));
	tmpone = malist;
	tmptwo = malist;
	i = -1;
	while (tmpone->next != NULL && ++i < n)
	{
		tmptwo = tmpone;
		tmpone = tmpone->next;
	}
	if (i == n)
	{
		tmpfree = tmpone;
		tmpone = tmpone->next;
		tmptwo->next = tmpone;
		free(tmpfree);
	}
	return (malist);
}
