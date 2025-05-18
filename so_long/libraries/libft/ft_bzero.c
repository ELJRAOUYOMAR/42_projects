/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:51:51 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/02 17:57:50 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (n > 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] = "Hello, World!"; // Initialize a string
	printf("Before ft_bzero: '%s'\n", str);
  	 ft_bzero(str, 6); // Set the first 6 bytes to zero
    	printf("After ft_bzero: '%s'\n", str); // Print the string directly
 Print the individual bytes to show their values
    	for (int i = 0; i < 10; i++)
    	{

        	 // Show ASCII values of the first 10 bytes
        	printf("Byte %d: %d\n", i, str[i]);
  	}
    	return 0;
}*/
