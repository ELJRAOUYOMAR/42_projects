/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:06:08 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/02 16:37:20 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size > len + 1)
	{
		ft_memcpy(dst, src, len + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (len);
}
/*int main() {
    char dest[10];
    const char *src = "Hello, World!";
    
    size_t len = ft_strlcpy(dest, src, );
    
    printf("Copied string: %s\n", dest);
    printf("Length of source: %zu\n", len);
    
    return 0;
}*/
