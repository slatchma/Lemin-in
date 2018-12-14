/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:20:43 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 20:20:51 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int i;
	int positif;
	int number;

	i = 0;
	number = 0;
	positif = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\v' ||
			str[i] == '\n' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		positif = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] <= 57)
	{
		number = number * 10 + ((int)str[i] - '0');
		i++;
	}
	return (number * positif);
}
