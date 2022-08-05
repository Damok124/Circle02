/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:10:11 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/05 02:08:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

void	ft_countnprintf(char c, int *total)
{
	*total += write(1, &c, 1);
}

void	ft_strprintf(char *str, int *total)
{
	int		n;

	n = -1;
	if (str == NULL)
		*total += write(1, "(null)", 6);
	else if (str)
		while (str[++n])
			ft_countnprintf(str[n], total);
}

void	ft_u_pn(unsigned int nbr, char *b, unsigned int len, int *total)
{
	if (nbr >= len)
		ft_u_pn(nbr / len, b, len, total);
	ft_countnprintf(b[nbr % len], total);
}

void	ft_pnbrprintf(int nb, int *total)
{
	long int	nbu;

	nbu = nb;
	if (nbu < 0)
	{
		*total += write(1, "-", 1);
		nbu = nbu * -1;
	}
	if (nbu >= 10)
		ft_pnbrprintf(nbu / 10, total);
	ft_countnprintf((nbu % 10) + '0', total);
}

void	ft_parsenprintf(char c, va_list vlist, int *total)
{
	if (c == 's')
		ft_strprintf(va_arg(vlist, char *), total);
	else if (c == 'd')
		ft_pnbrprintf(va_arg(vlist, int), total);
	else if (c && c == 'x')
		ft_u_pn(va_arg(vlist, unsigned int), "0123456789abcdef", 16, total);
}

int	ft_printf(const char *s, ...)
{
	va_list	vlist;
	int		total;
	int		index;

	total = 0;
	index = -1;
	va_start(vlist, s);
	while (s[++index])
	{
		if (s[index] != '%')
			ft_countnprintf(s[index], &total);
		else
		{
			index++;
			if (s[index])
				ft_parsenprintf(s[index], vlist, &total);
		}
	}
	va_end(vlist);
	return (total);
}
