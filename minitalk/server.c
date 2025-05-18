/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:52:38 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/04/06 15:01:52 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_pid(pid_t pid);

static void	handle_signal(int signum, siginfo_t *info, void *context);

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr("just one arg!!!\n");
		return (1);
	}
	get_pid(getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if ((sigaction(SIGUSR1, &sa, NULL) == -1) || (sigaction(SIGUSR2, &sa,
				NULL) == -1))
	{
		ft_putstr("sigaction error");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}

static void	get_pid(pid_t pid)
{
	write(1, "Process Id: ", 12);
	ft_putnbr(pid);
	ft_putchar('\n');
}

static void	handle_signal(int signum, siginfo_t *info,
		__attribute__((unused)) void *context)
{
	static unsigned char	c;
	static int				bit;
	static pid_t			client_pid;

	if (client_pid == 0 || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		bit = 0;
	}
	if (signum == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_putchar(c);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
