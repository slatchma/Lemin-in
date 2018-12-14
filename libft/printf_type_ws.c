/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_type_ws.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 00:19:32 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 00:23:07 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_octet_ls_two(int *octet, int i, wchar_t *wstr)
{
	int j;

	*octet = 0;
	j = 0;
	while (j < i)
	{
		*octet = *octet + ft_charlen_octet(wstr[j]);
		j++;
	}
	return (j);
}

static int	ft_octet_ls(t_modul analyze, wchar_t *wstr, int *len)
{
	int octet;
	int i;
	int j;
	int tmp;

	i = 0;
	octet = 0;
	tmp = *len;
	while (octet <= analyze.precision && wstr[i] != '\0')
	{
		octet = octet + ft_charlen_octet(wstr[i]);
		if (octet <= analyze.precision)
			i++;
	}
	j = ft_octet_ls_two(&octet, i, wstr);
	*len = *len - octet + i;
	if (wstr[j] != '\0' && analyze.precision > 0 && analyze.width == 0)
	{
		if (octet + i + wstr[j] > tmp)
			*len = i;
	}
	if (*len < 0)
		*len = 0;
	return (i);
}

static void	ft_wdisplay_two(t_modul analyze, wchar_t *wstrout,
			wchar_t *wstr, int len)
{
	int i;

	i = 0;
	len = len - analyze.precision;
	if (analyze.flag_neg == 1)
		len = 0;
	while (wstrout[len] != '\0')
	{
		if (i < analyze.precision)
			wstrout[len] = wstr[i];
		len++;
		i++;
	}
	i = 0;
	while (wstrout[i] != '\0')
	{
		if (wstrout[i] >= 0x7F && wstrout[i] <= 0xFF && MB_CUR_MAX == 1)
			ft_putchar(wstrout[i]);
		else
			ft_putwchar(wstrout[i]);
		i++;
	}
}

static void	ft_wdisplay(int len, t_modul analyze, wchar_t *wstrout,
			wchar_t *wstr)
{
	int i;

	i = 0;
	while (i < len)
	{
		wstrout[i] = ' ';
		i++;
	}
	wstrout[i] = '\0';
	if (analyze.flag_zero == 1)
	{
		i = 0;
		while (wstrout[i] != '\0')
		{
			wstrout[i] = '0';
			i++;
		}
	}
	ft_wdisplay_two(analyze, wstrout, wstr, len);
}

int			ft_type_ws(t_modul analyze, va_list ap, char tampon[2096])
{
	wchar_t	*wstr;
	wchar_t	*wstrout;
	int		len;

	wstr = va_arg(ap, wchar_t *);
	if (wstr != NULL)
	{
		if (ft_test_octet(wstr, analyze) == -1)
			return (-1);
	}
	if (wstr == NULL)
		wstr = L"(null)";
	ft_ws_len(&analyze, &len, wstr);
	analyze.precision = ft_octet_ls(analyze, wstr, &len);
	if ((wstrout = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))) == NULL)
		return (0);
	ft_putstr(tampon);
	ft_wdisplay(len, analyze, wstrout, wstr);
	len = ft_strlen(tampon) + ft_wstrlen(wstrout);
	free(wstrout);
	return (len);
}
