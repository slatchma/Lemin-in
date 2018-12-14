/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 18:03:14 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 18:47:07 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_flag(t_modul *analyze, char *modulo, int i)
{
	if (modulo[i] == '#')
		analyze->flag_hast = 1;
	if (modulo[i] == '0')
		analyze->flag_zero = 1;
	if (modulo[i] == '-')
		analyze->flag_neg = 1;
	if (modulo[i] == '+')
		analyze->flag_posit = 1;
	if (modulo[i] == ' ')
		analyze->flag_space = 1;
}

static int	ft_width(t_modul *analyze, char *modulo, int *i)
{
	analyze->width = 0;
	while (modulo[*i] >= '0' && modulo[*i] <= '9')
	{
		analyze->width = analyze->width * 10 + ((int)modulo[*i] - '0');
		*i = *i + 1;
	}
	*i = *i - 1;
	return (0);
}

static int	ft_precision(t_modul *analyze, char *modulo, int *i)
{
	int nbre_zero;

	*i = *i + 1;
	nbre_zero = *i;
	analyze->precision = 0;
	if (modulo[*i] == '#' || modulo[*i] == '-' ||
		modulo[*i] == '+' || modulo[*i] == ' ')
	{
		ft_flag(analyze, modulo, *i);
		return (0);
	}
	while (modulo[*i] >= '0' && modulo[*i] <= '9')
	{
		analyze->precision = analyze->precision * 10 + ((int)modulo[*i] - '0');
		*i = *i + 1;
	}
	*i = *i - 1;
	return (0);
}

static int	ft_prefix(t_modul *analyze, char *modulo, int *i)
{
	char *order;

	order = "hHlLjz";
	if (analyze->prefix == 0 || (ft_strsupchr(order, modulo[*i]) >
		ft_strsupchr(order, analyze->prefix)))
		analyze->prefix = modulo[*i];
	if (modulo[*i] == 'h' && modulo[*i + 1] == 'h')
	{
		if (analyze->prefix == 0 || (ft_strsupchr(order, 'H') >
			ft_strsupchr(order, analyze->prefix)))
			analyze->prefix = 'H';
		*i = *i + 1;
	}
	else if (modulo[*i] == 'l' && modulo[*i + 1] == 'l')
	{
		if (analyze->prefix == 0 || (ft_strsupchr(order, 'L') >
			ft_strsupchr(order, analyze->prefix)))
			analyze->prefix = 'L';
		*i = *i + 1;
	}
	return (4);
}

int			ft_parsing(char *modulo, va_list ap, char type, char tampon[2096])
{
	t_modul	analyze;
	int		i;
	int		octet;

	i = 0;
	octet = 0;
	ft_initialize(&analyze);
	while (modulo[i] != '\0')
	{
		if (modulo[i] == '#' || modulo[i] == '+' || modulo[i] ==
			'-' || modulo[i] == '0' || modulo[i] == ' ')
			ft_flag(&analyze, modulo, i);
		if (modulo[i] >= '1' && modulo[i] <= '9')
			ft_width(&analyze, modulo, &i);
		if (modulo[i] == '.')
			ft_precision(&analyze, modulo, &i);
		if (modulo[i] == 'h' || modulo[i] == 'l' || modulo[i] ==
			'j' || modulo[i] == 'z')
			ft_prefix(&analyze, modulo, &i);
		i++;
	}
	analyze.type = type;
	ft_feature(&analyze);
	octet = ft_typedefiner(analyze, ap, tampon);
	return (octet);
}
