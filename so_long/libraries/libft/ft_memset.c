/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:50:06 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/07 17:39:49 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) ptr;
	while (n > 0)
	{
		*tmp = (unsigned char) c;
		tmp++;
		n--;
	}
	return (ptr);
}
/*
#include <stdio.h>
int main()
{
        char str[50] = "Hello, World!";

        printf("Before ft_memset: %s\n", str);

        ft_memset(str, 'X', 5); // Set the first 5 characters to 'X'

        printf("After ft_memset: %s\n", str);

        return 0;

}
*/
