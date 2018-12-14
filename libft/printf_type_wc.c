/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_type_wc.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 00:15:30 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 00:17:33 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putwstrcas(wchar_t *wstr)
{
	int i;

	i = 0;
	if (wstr)
	{
		while (wstr[i] != '\0')
		{
			if (wstr[i] == 'S')
				ft_putwchar('\0');
			else
				ft_putwchar(wstr[i]);
			i++;
		}
	}
}

static void	ft_wdisplay_three(t_modul analyze, wchar_t *wstrout, wchar_t *wstr)
{
	int i;

	i = 0;
	if (wstr[0] == 'S' && analyze.czero == 1)
		ft_putwstrcas(wstrout);
	else
	{
		while (wstrout[i] != '\0')
		{
			if (wstrout[i] >= 0x7F && wstrout[i] <= 0xFF && MB_CUR_MAX == 1)
				ft_putchar(wstrout[i]);
			else
				ft_putwchar(wstrout[i]);
			i++;
		}
	}
}

static void	ft_wdisplay_two(int tab[2], t_modul analyze, wchar_t *wstrout,
			wchar_t *wstr)
{
	int i;
	int len;
	int wlen;

	len = tab[0];
	wlen = tab[1];
	i = 0;
	if (analyze.flag_neg == 1)
	{
		wstrout[0] = wstr[0];
		wlen = wlen - (ft_wstrlen(wstr) - 1);
		wstrout[wlen] = '\0';
	}
	while (wstrout[len] != '\0' && analyze.flag_neg != 1)
	{
		if (i < analyze.precision)
			wstrout[len] = wstr[i];
		len++;
		i++;
	}
	ft_wdisplay_three(analyze, wstrout, wstr);
}

static void	ft_wdisplay(int len, t_modul analyze, wchar_t *wstrout,
			wchar_t *wstr)
{
	int i;
	int wlen;
	int tab[2];

	i = 0;
	while (i < len)
	{
		wstrout[i] = ' ';
		i++;
	}
	wstrout[i] = '\0';
	wlen = i;
	if (analyze.flag_zero == 1)
	{
		i = 0;
		while (wstrout[i] != '\0')
		{
			wstrout[i] = '0';
			i++;
		}
	}
	len = len - analyze.precision;
	tab[0] = len;
	tab[1] = wlen;
	ft_wdisplay_two(tab, analyze, wstrout, wstr);
}

int			ft_type_wc(t_modul analyze, va_list ap, char tampon[2096])
{
	wint_t	wcharc;
	wchar_t	wstr[2];
	wchar_t	*wstrout;
	int		len;

	wcharc = va_arg(ap, wint_t);
	if (wcharc < 0 || ft_charlen_octet(wcharc) >
		(int)MB_CUR_MAX || ft_charlen_octet(wcharc) == -1)
		return (-1);
	wstr[0] = wcharc;
	wstr[1] = '\0';
	if (wcharc == 0)
	{
		wstr[0] = 'S';
		analyze.czero = 1;
	}
	ft_ws_len(&analyze, &len, wstr);
	if ((wstrout = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))) == NULL)
		return (0);
	ft_putstr(tampon);
	ft_wdisplay(len, analyze, wstrout, wstr);
	len = ft_strlen(tampon) + ft_wstrlen(wstrout);
	free(wstrout);
	return (len);
}
