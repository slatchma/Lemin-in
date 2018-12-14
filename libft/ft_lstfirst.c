/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfirst.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 21:01:27 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 21:06:50 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_llist		*ft_lstfirst(t_llist *malist, int val)
{
	t_llist	*maillon;

	maillon = (t_llist*)malloc(sizeof(t_llist));
	if (maillon == NULL)
		return (NULL);
	maillon->var = val;
	maillon->next = malist;
	return (maillon);
}
