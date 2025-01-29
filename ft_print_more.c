/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaben-sa <yaben-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:54 by yaben-sa          #+#    #+#             */
/*   Updated: 2025/01/28 14:33:33 by yaben-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += ft_put_unsigned(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_put_unsigned(n));
}

/*
** Prints a hexadecimal (base 16) number, in uppercase if uppercase=1,
** otherwise in lowercase.
*/
static int	ft_puthex(unsigned long nbr, int uppercase)
{
	char	c;
	int		count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, uppercase);
	c = (nbr % 16);
	if (c < 10)
		c += '0';
	else
	{
		c = c - 10;
		if (uppercase == 1)
			c += 'A';
		else
			c += 'a';
	}
	return (count + write(1, &c, 1));
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	return (ft_puthex(n, uppercase));
}
