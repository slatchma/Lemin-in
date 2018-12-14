/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_other.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 12:39:29 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 12:46:17 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_initialize(t_modul *analyze)
{
	analyze->flag_hast = 0;
	analyze->flag_zero = 0;
	analyze->flag_neg = 0;
	analyze->flag_posit = 0;
	analyze->flag_space = 0;
	analyze->prefix = 0;
	analyze->width = 0;
	analyze->precision = -1;
	analyze->type = 0;
	analyze->czero = 0;
	analyze->testfree = 0;
}

int			ft_typedefiner(t_modul analyze, va_list ap, char tampon[2096])
{
	int octet;

	octet = 0;
	if (analyze.type == 's' || analyze.type == 'S')
		octet = ft_type_s(analyze, ap, tampon);
	else if (analyze.type == 'p')
		octet = ft_type_p(analyze, ap, tampon) + octet;
	else if (analyze.type == 'd' ||
			analyze.type == 'i' || analyze.type == 'D')
		octet = ft_type_d(analyze, ap, tampon);
	else if (analyze.type == 'o' || analyze.type == 'O')
		octet = ft_type_o(analyze, ap, tampon);
	else if (analyze.type == 'u' || analyze.type == 'U')
		octet = ft_type_u(analyze, ap, tampon);
	else if (analyze.type == 'x' || analyze.type == 'X')
		octet = ft_type_x(analyze, ap, tampon);
	else if (analyze.type == 'c' || analyze.type == 'C')
		octet = ft_type_c(analyze, ap, tampon);
	else if (analyze.type == '%')
		octet = ft_type_m(analyze, tampon);
	else
		octet = ft_type_not(analyze, tampon);
	return (octet);
}

void		ft_feature(t_modul *analyze)
{
	if (analyze->flag_zero == 1 && analyze->flag_neg == 1)
		analyze->flag_zero = 0;
	if (analyze->flag_zero == 1 && analyze->precision != -1 &&
			(analyze->type == 'u' || analyze->type == 'x' ||
			analyze->type == 'X' || analyze->type == 'o' ||
			analyze->type == 'd'))
		analyze->flag_zero = 0;
	if (analyze->flag_space == 1 && analyze->flag_posit == 1)
		analyze->flag_space = 0;
	if (analyze->flag_hast == 1 && (analyze->type == 'c' ||
				analyze->type == 'd' || analyze->type == 'u'
				|| analyze->type == 's'))
		analyze->flag_hast = 0;
}

intmax_t	ft_sign(intmax_t nbre, int **sign)
{
	if (nbre < 0)
	{
		nbre = nbre * -1;
		**sign = 1;
	}
	return (nbre);
}
