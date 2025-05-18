/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adresse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:40:42 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/28 10:35:37 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_adresse(void *n)
{
	char			buffer[16];
	int				counter;
	char			*base;
	unsigned long	adresse;
	long int		i;

	base = "0123456789abcdef";
	counter = 0;
	adresse = (unsigned long) n;
	if (adresse == 0)
		return (write(1, "(nil)", 5));
	counter += write(1, "0x", 2);
	i = 0;
	while (adresse > 0)
	{
		buffer[i++] = base[adresse % 16];
		adresse /= 16;
	}
	while (i > 0)
		counter += (ft_putchar(buffer[--i]));
	return (counter);
}
