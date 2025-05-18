/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:23:03 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/02 21:39:18 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	digits[10];
	long	nb;
	int		i;

	i = 0;
	nb = n;
	if (nb == 0)
	{
		write(fd, "0", 1);
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		digits[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (i > 0)
		write(fd, &digits[--i], 1);
}
/*#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	ssize_t fd = open("txt.sh", O_CREAT | O_RDWR | O_APPEND);
	char string[] = "touch file\n";
        size_t len = ft_strlen(string);

	if (fd == -1)
	{	
		printf("There is a problem with this file");
		return (1);
	}
	printf("fd = %zd", fd);
	write(fd, string, len);
	ft_putnbr_fd(789, fd);
}*/
