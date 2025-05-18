/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:14:21 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/28 21:37:22 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	char	digits[11];
	int		i;
	int		counter;
	long	n;

	i = 0;
	counter = 0;
	n = nb;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
	while (n > 0)
	{
		digits[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		counter += ft_putchar(digits[i]);
	return (counter);
}

int	ft_putunsignednbr(unsigned int n)
{
	char			digits[10];
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		digits[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		counter += ft_putchar(digits[--i]);
	return (counter);
}

int	ft_putstring(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		counter += ft_putchar(*str++);
	}
	return (counter);
}
