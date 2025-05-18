/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:24:16 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/04/06 16:41:28 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
int		check_digit_space(char *str);
void	check_args(int ac);
void	send_signal(pid_t pid, char c);
void	send_message(pid_t pid, char *str);
#endif
