/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:24:43 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/04/06 17:39:59 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_args(int ac)
{
	if (ac != 3)
	{
		ft_putstr("Usage: ./client <PID> <Message>\n");
		exit(1);
	}
}

void	send_message(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_signal(pid, str[i++]);
	send_signal(pid, '\0');
}
