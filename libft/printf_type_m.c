/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_type_m.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 12:51:16 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 17:33:51 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_m(int len, t_modul analyze, char *strout)
{
	int i;

	i = 0;
	while (i < len)
	{
		strout[i] = ' ';
		i++;
	}
	strout[i] = '\0';
	if (analyze.flag_zero == 1)
	{
		i = 0;
		while (strout[i] != '\0')
		{
			strout[i] = '0';
			i++;
		}
	}
}

static void	ft_display(int len, t_modul analyze, char *strout, char *str)
{
	int i;

	ft_init_m(len, analyze, strout);
	i = 0;
	len = len - analyze.precision;
	if (analyze.flag_neg == 1)
		len = 0;
	while (strout[len] != '\0')
	{
		if (i < analyze.precision)
			strout[len] = str[i];
		len++;
		i++;
	}
	ft_putstr(strout);
}

int			ft_type_m(t_modul analyze, char tampon[2096])
{
	char	str[2];
	char	*strout;
	int		len;

	analyze.precision = -1;
	str[0] = '%';
	str[1] = '\0';
	ft_s_len(&analyze, &len, str);
	if ((strout = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	ft_putstr(tampon);
	ft_display(len, analyze, strout, str);
	len = ft_strlen(tampon) + ft_strlen(strout);
	free(strout);
	return (len);
}
