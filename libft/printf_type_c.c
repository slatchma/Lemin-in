/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_type_c.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 17:27:07 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 00:07:08 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putstrcas(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == 'S')
				ft_putchar('\0');
			else
				ft_putchar(str[i]);
			i++;
		}
	}
}

static void		ft_display_two(int len, t_modul analyze,
				char *strout, char *str)
{
	int i;

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
	if (str[0] == 'S' && analyze.czero)
		ft_putstrcas(strout);
	else
		ft_putstr(strout);
}

static void		ft_display(int len, t_modul analyze, char *strout, char *str)
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
	ft_display_two(len, analyze, strout, str);
}

static int		ft_type_simplec(t_modul analyze, va_list ap, char tampon[2096])
{
	int		charc;
	char	str[2];
	char	*strout;
	int		len;

	charc = va_arg(ap, int);
	str[0] = charc;
	str[1] = '\0';
	if (charc == 0)
	{
		str[0] = 'S';
		analyze.czero = 1;
	}
	ft_s_len(&analyze, &len, str);
	if ((strout = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	ft_putstr(tampon);
	ft_display(len, analyze, strout, str);
	len = ft_strlen(tampon) + ft_strlen(strout);
	free(strout);
	return (len);
}

int				ft_type_c(t_modul analyze, va_list ap, char tampon[2096])
{
	analyze.precision = -1;
	if (analyze.prefix == 'l' || analyze.type == 'C')
		return (ft_type_wc(analyze, ap, tampon));
	else
		return (ft_type_simplec(analyze, ap, tampon));
	return (-1);
}
