/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstcompt.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 21:01:12 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 21:05:55 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcompt(t_llist *malist)
{
	t_llist *tmp;
	int		i;

	tmp = malist;
	i = 0;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
