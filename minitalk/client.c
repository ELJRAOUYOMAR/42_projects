/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:45:20 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/04/06 17:38:40 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_flag = 0;

static void	check_response(int sig);
static void	send_signal(pid_t pid, char c);
static void	send_massage(pid_t pid, char *str);

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, check_response);
	if (ac != 3)
	{
		ft_putstr("Usage: ./client <PID> <Message>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 1 || !check_digit_space(av[1]))
	{
		ft_putstr("Invalid PID, please enter a valid pid number\n");
		return (1);
	}
	send_massage(pid, av[2]);
	return (0);
}

static void	check_no_process(pid_t pid)
{
	while (g_flag == 0)
	{
		if (kill(pid, 0) == -1)
		{
			exit(1);
		}
	}
}

static void	send_signal(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr("SIGUSR1 error, no process has this pid");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr("SIGUSR2 error, no process has this pid");
				exit(1);
			}
		}
		check_no_process(pid);
		g_flag = 0;
		bit--;
	}
}

static void	send_massage(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_signal(pid, str[i++]);
	send_signal(pid, '\0');
}

static void	check_response(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
}
