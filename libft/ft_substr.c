/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:32:52 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/02 18:03:21 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
	{
		len = s_len - start;
	}
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}
/*
int main() {
    const char *original = "Hello, World!";
    unsigned int start = 7;
    size_t len = 5;

    char *substring = ft_substr(original, start, len);
    if (substring) {
        printf("Substring: %s\n", substring);
        free(substring);  // Don't forget to free the allocated memory!
    } else {
        printf("Failed to allocate memory for the substring.\n");
    }

    return 0;
}
*/
