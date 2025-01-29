/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaben-sa <yaben-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:54:59 by yaben-sa          #+#    #+#             */
/*   Updated: 2025/01/28 14:32:48 by yaben-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(const char *s);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_dec(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, int uppercase);

#endif
