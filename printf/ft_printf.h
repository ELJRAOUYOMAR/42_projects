/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 06:49:52 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/29 11:27:46 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

/* helper functions */

/* ft_puts*/
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putunsignednbr(unsigned int n);
int	ft_putstring(char *str);

/* ft_hexa_puts */
int	ft_put_lowerhexa(unsigned int n);
int	ft_put_upperhexa(unsigned int n);

/* ft_put_adresse*/
int	ft_put_adresse(void *n);

/* the main function */
int	ft_printf(const char *str, ...);

#endif
