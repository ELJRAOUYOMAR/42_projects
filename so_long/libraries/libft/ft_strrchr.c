/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:53:14 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/05 09:11:09 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*tmp_char;
	unsigned int	i;
	char			to_char;

	i = 0;
	tmp_char = NULL;
	to_char = (char) c;
	while (s[i])
	{
		if (s[i] == to_char)
			tmp_char = (char *) &s[i];
		i++;
	}
	if (s[i] == c)
		tmp_char = (char *) &s[i];
	return (tmp_char);
}
/*
#include <stdio.h>
int main() {
    const char *str = "Hello, world!";

    // Test case 1: Searching for 'o'
    char *result = ft_strrchr(str, 'o');
    if (result)
        printf("Found 'o' at: %ld\n", result - str);
    else
        printf("'o' not found.\n");

    // Test case 2: Searching for 'z'
    result = ft_strrchr(str, 'z');
    if (result)
        printf("Found 'z' at: %ld\n", result - str);
    else
        printf("'z' not found.\n");

    return 0;
}*/
