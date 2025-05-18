/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:21:07 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/10/26 11:37:32 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && big[i + j] && i + j < len)
		{
			j++;
		}
		if (little[j] == 0)
		{
			return ((char *) big + i);
		}
		i++;
	}
	return (0);
}
/*int main() {
    const char *haystack = "Hello, this is a simple test string.";
    const char *needle = "";
    size_t len = 23; // Length to search within the haystack

    char *result = ft_strnstr(haystack, needle, len);


    printf("Found: %s\n", result);

    return 0;
}*/
