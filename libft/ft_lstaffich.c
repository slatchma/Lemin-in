/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstaffich.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 21:00:05 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 21:05:30 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaffich(t_llist *malist)
{
	t_llist *tmp;

	tmp = malist;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->var);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
