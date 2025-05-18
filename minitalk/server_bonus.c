/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:29:11 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/04/06 16:08:20 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	get_pid(pid_t pid);
static void	process_message(unsigned char c, int sender_pid,
				int *message_received);
static void	handle_signal(int signum, siginfo_t *info, void *context);

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr("just one arg\n");
		return (1);
	}
	get_pid(getpid());
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &sa, NULL)) == -1 || (sigaction(SIGUSR2, &sa,
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

static void	process_message(unsigned char c, int sender_pid,
		int *message_received)
{
	ft_putchar(c);
	if (c == '\0')
	{
		if (kill(sender_pid, SIGUSR1) == -1)
		{
			ft_putstr("no such process");
			exit(1);
		}
		if (!*message_received)
		{
			write(1, "\nthis is a message from: ", 26);
			ft_putnbr(sender_pid);
			ft_putchar('\n');
			*message_received = 1;
		}
	}
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit;
	static int				sender_pid;
	static int				message_received;

	(void)context;
	if (sender_pid == 0 || sender_pid != info->si_pid)
	{
		sender_pid = info->si_pid;
		c = 0;
		bit = 0;
		message_received = 0;
	}
	if (signum == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		process_message(c, sender_pid, &message_received);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR2);
}
