/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_type_d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 18:55:20 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 00:07:55 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_conversion(t_modul *analyze, va_list ap, int *sign)
{
	intmax_t	recup;

	if (analyze->prefix == 'z')
		recup = (ssize_t)va_arg(ap, uintmax_t *);
	else if (analyze->prefix == 'j')
		recup = (intmax_t)va_arg(ap, uintmax_t *);
	else if (analyze->prefix == 'L')
		recup = (long long)va_arg(ap, uintmax_t *);
	else if (analyze->prefix == 'l' || analyze->type == 'D')
		recup = (long)va_arg(ap, uintmax_t *);
	else if (analyze->prefix == 'H')
		recup = (char)va_arg(ap, uintmax_t *);
	else if (analyze->prefix == 'h')
		recup = (short)va_arg(ap, uintmax_t *);
	else
		recup = (int)va_arg(ap, uintmax_t *);
	recup = ft_sign(recup, &sign);
	if (recup)
		analyze->testfree = 1;
	return (ft_itoa_base((uintmax_t)recup, 10, "0123456789"));
}

static void	ft_d_len(t_modul *analyze, int *len, char *str, int sign)
{
	if (sign == 1)
		analyze->flag_space = 0;
	if (analyze->width >= (analyze->precision + 1) && analyze->precision != -1)
		analyze->flag_space = 0;
	if (analyze->precision < (int)ft_strlen(str) && analyze->precision != 0)
		analyze->precision = (int)ft_strlen(str);
	if (analyze->precision == 0 && ft_strcmp(str, "0") != 0)
		analyze->precision = (int)ft_strlen(str);
	if (analyze->flag_space == 1 && sign == 0)
		analyze->precision = analyze->precision + 1;
	if (analyze->flag_posit == 1 && sign == 0)
		analyze->precision = analyze->precision + 1;
	if (sign == 1)
		analyze->precision = analyze->precision + 1;
	if (analyze->width < analyze->precision)
		analyze->width = analyze->precision;
	*len = analyze->width;
}

static void	ft_write_d(t_modul analyze, char *str,
		char *strout, int i_j_sign[3])
{
	while (i_j_sign[0]-- && i_j_sign[1] >= 0 && analyze.precision != 0)
	{
		strout[i_j_sign[0]] = str[i_j_sign[1]];
		i_j_sign[1] = i_j_sign[1] - 1;
		analyze.precision = analyze.precision - 1;
	}
	while (analyze.precision != 0)
	{
		strout[i_j_sign[0]] = '0';
		analyze.precision = analyze.precision - 1;
		i_j_sign[0] = i_j_sign[0] - 1;
	}
	if (analyze.flag_space == 1)
		strout[0] = ' ';
	if (analyze.flag_zero == 1)
		i_j_sign[0] = -1;
	if (i_j_sign[2] == 1)
		strout[i_j_sign[0] + 1] = '-';
	if (analyze.flag_posit == 1 && i_j_sign[2] == 0)
		strout[i_j_sign[0] + 1] = '+';
}

static int	ft_type_d_two(char tampon[2096], char *strout)
{
	ft_putstr(tampon);
	ft_putstr(strout);
	return (ft_strlen(tampon) + ft_strlen(strout));
}

int			ft_type_d(t_modul analyze, va_list ap, char tampon[2096])
{
	char	*str;
	char	*strout;
	int		len;
	int		i_j_sign[3];

	i_j_sign[2] = 0;
	str = ft_conversion(&analyze, ap, &i_j_sign[2]);
	ft_d_len(&analyze, &len, str, i_j_sign[2]);
	if ((strout = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	strout = ft_memset(strout, ' ', (size_t)len);
	strout[len] = '\0';
	if (analyze.flag_zero == 1)
		strout = ft_memset(strout, '0', (size_t)len);
	if (analyze.flag_neg == 1)
		i_j_sign[0] = analyze.precision;
	else
		i_j_sign[0] = len;
	i_j_sign[1] = ft_strlen(str) - 1;
	ft_write_d(analyze, str, strout, i_j_sign);
	len = ft_type_d_two(tampon, strout);
	free(strout);
	if (analyze.testfree == 1)
		free(str);
	return (len);
}
