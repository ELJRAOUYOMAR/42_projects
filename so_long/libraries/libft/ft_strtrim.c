/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:08:03 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/07 16:50:47 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_exist(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_trim_len;
	size_t	end;
	char	*str_trim;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && is_exist(*s1, set))
	{
		s1++;
	}
	end = ft_strlen(s1);
	while (end > 0 && is_exist(s1[end - 1], set))
		end--;
	str_trim_len = end;
	str_trim = (char *)malloc(str_trim_len + 1);
	if (!str_trim)
		return (NULL);
	ft_memcpy(str_trim, s1, str_trim_len);
	str_trim[str_trim_len] = '\0';
	return (str_trim);
}
/*
int main() {
    const char *s1 = "xHello, World!ll";
    const char *set = "lx";

    char *trimmed = ft_strtrim(s1, set);
    if (trimmed) {
        printf("Trimmed string: '%s'\n", trimmed);
        free(trimmed);  // Don't forget to free the allocated memory!
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
