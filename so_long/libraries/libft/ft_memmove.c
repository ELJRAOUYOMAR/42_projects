/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:09:19 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/10/25 22:24:45 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_tmp;
	char	*src_tmp;
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_tmp = (char *) dest;
	src_tmp = (char *) src;
	if (dest_tmp > src_tmp)
	{
		while (n-- > 0)
		{
			dest_tmp[n] = src_tmp[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dest);
}
/*
int main() {
    char str[] = "Hello, World!";
    
    // Print original string
    printf("Original string: %s\n", str);

    // Use memmove to move "World" to the beginning of the string
    // Overlapping regions, so memmove should be used instead of memcpy
    ft_memmove(str, str + 7, 6);  // Move "World!" to the start
    str[6] = '\0';              // Null-terminate the new string

    // Print modified string
    printf("Modified string: %s\n", str);

    return 0;
}
*/
