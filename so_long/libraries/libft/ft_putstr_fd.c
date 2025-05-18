/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:14:48 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/05 07:01:48 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}
/*
#include <fcntl.h>
int main()
{
	char str[] = "\nHello worldsdfsdfsd ";
	int fd = open("test.txt", O_RDWR | O_APPEND | O_CREAT);
}
*/
