/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandroso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:30:01 by nandroso          #+#    #+#             */
/*   Updated: 2023/09/01 20:10:30 by nandroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_char(va_arg(args, int));
	else if (format == 'i' || format == 'd')
		len += ft_int(va_arg(args, int));
	else if (format == 's')
		len += ft_str(va_arg(args, char *));
	else if (format == 'u')
		len += ft_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_pointer(va_arg(args, unsigned long));
	else if (format == '%')
		len += ft_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
