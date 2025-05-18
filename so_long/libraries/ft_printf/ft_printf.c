/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:47:16 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/23 03:50:18 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_format(va_list args, char format)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter = ft_putchar(va_arg(args, int));
	else if (format == 's')
		counter = ft_putstring(va_arg(args, char *));
	else if (format == 'p')
		counter = ft_put_adresse(va_arg(args, void *));
	else if (format == 'i' || format == 'd')
		counter = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		counter = ft_putunsignednbr(va_arg(args, unsigned int));
	else if (format == 'x')
		counter = ft_put_lowerhexa(va_arg(args, unsigned int));
	else if (format == 'X')
		counter = ft_put_upperhexa(va_arg(args, unsigned int));
	else if (format == '%')
		counter = ft_putchar('%');
	else
	{
		counter += ft_putchar('%');
		counter += ft_putchar(format);
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '\0')
				return (-1);
			else
				counter += process_format(args, *(++str));
		}
		else
			counter += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (counter);
}
