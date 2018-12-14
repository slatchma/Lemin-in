/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_type_p.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 17:41:35 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 00:15:09 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_p_len(t_modul *analyze, int *len, char *str)
{
	int lenstr;

	lenstr = (int)ft_strlen(str);
	if (analyze->czero == 1)
		lenstr = 0;
	*len = analyze->precision;
	if (lenstr > analyze->precision)
		*len = lenstr;
	if (analyze->width > lenstr + 2)
		*len = analyze->width - 2;
	*len = *len + 2;
}

static void	ft_type_p_neg(t_modul analyze, int len, char *strout, char *str)
{
	int i;
	int j;

	i = 2;
	strout[0] = '0';
	strout[1] = 'x';
	if ((int)ft_strlen(str) > analyze.precision && analyze.czero == 0)
		analyze.precision = (int)ft_strlen(str);
	while (i < analyze.precision + 2)
	{
		strout[i] = '0';
		i++;
	}
	i = len - 1;
	while (strout[i] == ' ')
	{
		i--;
	}
	j = (int)ft_strlen(str) - 1;
	while (j >= 0 && analyze.czero == 0)
	{
		strout[i] = str[j];
		i--;
		j--;
	}
}

static void	ft_type_p_three(t_modul analyze, char *strout, char tampon[2096],
		int i_j_len[3])
{
	if (analyze.flag_zero == 1)
	{
		strout[0] = '0';
		strout[1] = 'x';
	}
	else
	{
		i_j_len[0] = 0;
		while (strout[i_j_len[0]] == ' ' && analyze.flag_neg == 0)
		{
			i_j_len[0]++;
		}
		strout[i_j_len[0] - 1] = 'x';
		strout[i_j_len[0] - 2] = '0';
	}
	ft_putstr(tampon);
	ft_putstr(strout);
}

static void	ft_type_p_two(t_modul analyze, char *strout, char *str,
		int i_j_len[3])
{
	strout = ft_memset(strout, ' ', (size_t)i_j_len[2]);
	strout[i_j_len[2]] = '\0';
	if (analyze.flag_zero == 1)
		strout = ft_memset(strout, '0', (size_t)i_j_len[2]);
	if (analyze.flag_neg == 1)
		ft_type_p_neg(analyze, i_j_len[2], strout, str);
	else
	{
		i_j_len[0] = i_j_len[2] - 1;
		while (analyze.precision > 0)
		{
			strout[i_j_len[0]] = '0';
			i_j_len[0]--;
			analyze.precision = analyze.precision - 1;
		}
		i_j_len[0] = i_j_len[2] - 1;
		i_j_len[1] = (int)ft_strlen(str) - 1;
		while (i_j_len[1] >= 0 && analyze.czero == 0)
		{
			strout[i_j_len[0]] = str[i_j_len[1]];
			i_j_len[0]--;
			i_j_len[1]--;
		}
	}
}

int			ft_type_p(t_modul analyze, va_list ap, char tampon[2096])
{
	void	*pointeur;
	char	*str;
	char	*strout;
	int		i_j_len[3];

	pointeur = va_arg(ap, void *);
	str = ft_itoa_base((uintmax_t)pointeur, 16, "0123456789abcdef");
	if (analyze.precision == 0 && str[0] == '0')
		analyze.czero = 1;
	ft_p_len(&analyze, &i_j_len[2], str);
	if ((strout = (char *)malloc(sizeof(char) * (i_j_len[2] + 1))) == NULL)
		return (0);
	ft_type_p_two(analyze, strout, str, i_j_len);
	ft_type_p_three(analyze, strout, tampon, i_j_len);
	i_j_len[2] = ft_strlen(tampon) + ft_strlen(strout);
	free(strout);
	if (pointeur)
		free(str);
	return (i_j_len[2]);
}
