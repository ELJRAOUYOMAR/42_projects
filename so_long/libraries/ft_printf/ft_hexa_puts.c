/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_puts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:17:56 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/28 09:43:18 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_lowerhexa(unsigned int n)
{
	char	buffer[16];
	int		counter;
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	counter = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i > 0)
		counter += ft_putchar(buffer[--i]);
	return (counter);
}

int	ft_put_upperhexa(unsigned int n)
{
	char	buffer[16];
	char	*base;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	base = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i > 0)
		counter += ft_putchar(buffer[--i]);
	return (counter);
}
