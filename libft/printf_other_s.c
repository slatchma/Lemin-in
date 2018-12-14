/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_other_s.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 17:25:39 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 00:04:16 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_s_len(t_modul *analyze, int *len, char *str)
{
	if (analyze->precision > (int)ft_strlen(str) || analyze->precision == -1)
		analyze->precision = (int)ft_strlen(str);
	if (analyze->precision == -1)
		analyze->precision = 0;
	*len = analyze->precision;
	if (analyze->precision < analyze->width)
		*len = analyze->width;
}

void	ft_ws_len(t_modul *analyze, int *len, wchar_t *wstr)
{
	if (analyze->precision > (int)ft_wstrlen(wstr) || analyze->precision == -1)
		analyze->precision = (int)ft_wstrlen(wstr);
	if (analyze->precision == -1)
		analyze->precision = 0;
	*len = analyze->precision;
	if (analyze->precision < analyze->width)
		*len = analyze->width;
}

int		ft_wstrlen(wchar_t *str)
{
	int octet;
	int i;

	i = 0;
	octet = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 0x7F)
			octet = octet + 1;
		else if (str[i] >= 0x80 && str[i] <= 0x7FF)
			octet = octet + 2;
		else if (str[i] >= 0x800 && str[i] <= 0xFFFF)
			octet = octet + 3;
		else if (str[i] >= 0x10000 && str[i] <= 0x1FFFFF)
			octet = octet + 4;
		if (str[i] >= 0x7F && str[i] <= 0xFF && MB_CUR_MAX == 1)
			octet = octet - 1;
		i++;
	}
	return (octet);
}

int		ft_charlen_octet(wchar_t str)
{
	int octet;

	octet = 0;
	if (str >= 0xD800 && str <= 0xDFFF)
		octet = -1;
	else if (str <= 0xFF)
		octet = 1;
	else if (str <= 0x7FF)
		octet = 2;
	else if (str <= 0xFFFF)
		octet = 3;
	else if (str <= 0x10FFFF)
		octet = 4;
	else
		octet = -1;
	return (octet);
}

int		ft_test_octet(wchar_t *wstr, t_modul analyze)
{
	int i;
	int result;

	i = 0;
	result = 1;
	if (analyze.precision == -1)
		analyze.precision = (int)ft_wstrlen(wstr);
	while (wstr[i] != '\0' && result != -1 && i < analyze.precision)
	{
		if (ft_charlen_octet(wstr[i]) > (int)MB_CUR_MAX ||
			ft_charlen_octet(wstr[i]) == -1)
			result = -1;
		i++;
	}
	return (result);
}
