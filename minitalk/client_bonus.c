/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:25:08 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/04/06 17:37:21 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int			g_flag;

static void	check_response(int sig);
static void	ack_handler(int signum);

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	signal(SIGUSR1, check_response);
	signal(SIGUSR2, check_response);
	check_args(ac);
	pid = ft_atoi(av[1]);
	if (pid <= 1 || !check_digit_space(av[1]))
	{
		ft_putstr("Invalid pid, please enter a valid pid number\n");
		return (1);
	}
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr("sigaction error");
		return (1);
	}
	send_message(pid, av[2]);
	pause();
	return (0);
}

static void	loop_over_string(pid_t pid)
{
	while (g_flag == 0)
	{
		if (kill(pid, 0) == -1)
		{
			exit(1);
		}
	}
}

void	send_signal(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr("SIGUSR1 error, no process with this pid");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr("SIGUSR1 error, no process with this pid");
				exit(1);
			}
		}
		loop_over_string(pid);
		g_flag = 0;
		bit--;
	}
}

static void	ack_handler(int signum)
{
	if (signum == SIGUSR2)
		g_flag = 0;
	if (signum == SIGUSR1)
	{
		ft_putstr("Message received by server\n");
		exit(0);
	}
}

static void	check_response(int sig)
{
	if (sig == SIGUSR2)
		g_flag = 1;
}
