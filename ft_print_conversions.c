/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaben-sa <yaben-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:56:26 by yaben-sa          #+#    #+#             */
/*   Updated: 2025/01/28 13:56:33 by yaben-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints a single character. */
int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

/* Prints a string (null-terminated). */
int	ft_print_str(const char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}

/* Prints a signed decimal integer. */
static int	ft_putnbr_rec(long n)
{
	char	c;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr_rec(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_print_dec(int n)
{
	long	nb;

	nb = (long)n;
	return (ft_putnbr_rec(nb));
}
