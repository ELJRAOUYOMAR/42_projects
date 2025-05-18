/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:01:12 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/04/04 18:44:47 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
int		check_digit_space(char *str);

#endif
