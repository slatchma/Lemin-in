/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:30:10 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 18:54:42 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwchar(wchar_t nr)
{
	int i;

	i = 1;
	if (nr <= 0x7F)
		ft_putchar(nr);
	else if (nr >= 0x80 && nr <= 0x7FF && (i = 2))
	{
		ft_putchar((nr >> 6) + 0xC0);
		ft_putchar((nr & 0x3F) + 0x80);
	}
	else if (nr >= 0x800 && nr <= 0xFFFF && (i = 3))
	{
		ft_putchar((nr >> 12) + 0xE0);
		ft_putchar(((nr >> 6) & 0x3F) + 0x80);
		ft_putchar((nr & 0x3F) + 0x80);
	}
	else if (nr >= 0x10000 && nr <= 0x1FFFFF && (i = 4))
	{
		ft_putchar((nr >> 18) + 0xF0);
		ft_putchar(((nr >> 12) & 0x3F) + 0x80);
		ft_putchar(((nr >> 6) & 0x3F) + 0x80);
		ft_putchar((nr & 0x3F) + 0x80);
	}
	return (i);
}
