/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 19:24:35 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 16:13:00 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_typefinder_two(char *txt, int j, char *type)
{
	while (ft_strsupchr("0123456789. hljz#-+", txt[j]) != -1 && txt[j] != '\0')
	{
		j++;
	}
	*type = txt[j];
	j++;
	return (j);
}

static char	*ft_typefinder(char *txt, va_list ap,
		int *octet, char tampon[2096])
{
	int		j;
	char	*modulo;
	int		test;
	char	type;

	j = 0;
	test = 0;
	modulo = NULL;
	type = 0;
	txt = txt + 1;
	j = ft_typefinder_two(txt, j, &type);
	modulo = ft_strnew(j);
	ft_strncpy(modulo, txt, j);
	if (type == '\0')
		txt = txt + j - 2;
	else
		txt = txt + j - 1;
	test = ft_parsing(modulo, ap, type, tampon);
	free(modulo);
	if (test == -1)
		*octet = -1;
	else
		*octet = *octet + test;
	return (txt);
}

static char	*ft_execut(int i_octet[2], va_list ap, char tampon[2096], char *txt)
{
	if (txt[0] == '%')
	{
		tampon[i_octet[0]] = '\0';
		txt = ft_typefinder(txt, ap, &i_octet[1], tampon);
		ft_bzero(tampon, i_octet[0]);
		i_octet[0] = 0;
	}
	else if (i_octet[1] != -1)
	{
		tampon[i_octet[0]] = txt[0];
		i_octet[0]++;
	}
	if (i_octet[0] == 2090)
	{
		ft_putstr(tampon);
		ft_bzero(tampon, i_octet[0]);
		i_octet[0] = 0;
	}
	return (txt);
}

int			ft_printf(char *txt, ...)
{
	va_list	ap;
	char	tampon[2096];
	int		i_octet[2];

	i_octet[0] = 0;
	i_octet[1] = 0;
	va_start(ap, txt);
	while (txt[0] != '\0' && i_octet[1] != -1)
	{
		txt = ft_execut(i_octet, ap, tampon, txt);
		txt++;
	}
	if (i_octet[1] != -1)
	{
		tampon[i_octet[0]] = '\0';
		ft_putstr(tampon);
		i_octet[1] = ft_strlen(tampon) + i_octet[1];
	}
	va_end(ap);
	return (i_octet[1]);
}
