/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:24:53 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 19:04:46 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_taille(int nb, int taille)
{
	int i;

	if (nb >= 1000000000)
		return (taille + 9);
	i = 10;
	while (nb >= i)
	{
		i = i * 10;
		taille = taille + 1;
	}
	return (taille);
}

static void		ft_ecriture(char *itoto, int nb, int taille)
{
	int i;
	int vtaille;

	vtaille = taille;
	i = nb % 10;
	if (nb / 10 > 0)
	{
		ft_ecriture(itoto, nb / 10, vtaille - 1);
	}
	itoto[vtaille] = i + 48;
}

static void		ft_init(int *taille, int *signe, int *flow, int *nb)
{
	*taille = 1;
	*signe = 1;
	*flow = 0;
	if (*nb == -2147483648)
	{
		*taille = 3;
		*signe = -1;
		*flow = 1;
		*nb = 147483648;
	}
	if (*nb < 0)
	{
		*signe = -1;
		*nb = *nb * -1;
		*taille = *taille + 1;
	}
}

char			*ft_itoa(int nb)
{
	int		taille;
	int		signe;
	int		flow;
	char	*itoto;

	ft_init(&taille, &signe, &flow, &nb);
	taille = ft_taille(nb, taille);
	itoto = (char*)malloc(sizeof(char) * (taille + 1));
	if (!itoto)
		return (NULL);
	itoto[taille] = '\0';
	taille--;
	ft_ecriture(itoto, nb, taille);
	if (signe < 0)
		itoto[0] = '-';
	if (flow == 1)
		itoto[1] = '2';
	return (itoto);
}
