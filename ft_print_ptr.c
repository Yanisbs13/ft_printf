/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaben-sa <yaben-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:57:56 by yaben-sa          #+#    #+#             */
/*   Updated: 2025/01/28 14:24:58 by yaben-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long nbr)
{
	char	c;
	int		count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex_ptr(nbr / 16);
	c = (nbr % 16);
	if (c < 10)
		c += '0';
	else
		c = (c - 10) + 'a';
	return (count + write(1, &c, 1));
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_puthex_ptr(ptr);
	return (count);
}
