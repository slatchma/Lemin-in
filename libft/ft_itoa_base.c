/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 17:13:28 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 17:16:01 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t	ft_nbrelen(uintmax_t n, int base)
{
	uintmax_t len;

	len = 0;
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char				*ft_itoa_base(uintmax_t n, int base, char *basestyle)
{
	uintmax_t	len;
	char		*str;

	str = NULL;
	if (n == 0)
		return ("0");
	len = ft_nbrelen(n, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = basestyle[n % base];
		n = n / base;
	}
	return (str);
}
