/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:47:50 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/02 16:21:12 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (!dest && !src)
		return (dest);
	dest_tmp = (unsigned char *) dest;
	src_tmp = (unsigned char *) src;
	while (n > 0)
	{
		*(dest_tmp++) = *(src_tmp++);
		n--;
	}
	return (dest);
}
/*#include <stdio.h>
int main()
{
    char src[] = "Hello, World!";
    char dest[50];

    printf("Source string: '%s'\n", src);

    ft_memcpy(dest, src, ft_strlen(src) + 1);

    printf("dst string after memcpy: '%s'\n", dest);

    return 0;
}*/
