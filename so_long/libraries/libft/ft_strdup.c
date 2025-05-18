/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:09:29 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/02 17:23:29 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*start;

	ptr = (char *) malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	start = ptr;
	while (*s)
	{
		*ptr = *s;
		s++;
		ptr++;
	}
	*ptr = '\0';
	return (start);
}
/*
int main()
{
    char source[] = "GeeksForGeeks";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = ft_strdup(source); 

    printf("%s", target);
    return 0;
}*/
