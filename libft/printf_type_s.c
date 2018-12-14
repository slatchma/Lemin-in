/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_type_s.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 17:45:24 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 00:06:30 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_display_two(t_modul analyze, int len, char *strout, char *str)
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
	ft_putstr(strout);
}

static void	ft_display(int len, t_modul analyze, char *strout, char *str)
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
	ft_display_two(analyze, len, strout, str);
}

int			ft_type_s(t_modul analyze, va_list ap, char tampon[2096])
{
	char	*str;
	char	*strout;
	int		len;

	if (analyze.prefix == 'l' || analyze.type == 'S')
		return (ft_type_ws(analyze, ap, tampon));
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		ft_s_len(&analyze, &len, str);
		if ((strout = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (0);
		ft_putstr(tampon);
		ft_display(len, analyze, strout, str);
		len = ft_strlen(tampon) + ft_strlen(strout);
		free(strout);
		return (len);
	}
	return (-1);
}
