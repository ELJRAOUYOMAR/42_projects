/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:48:28 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/07 16:47:30 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[len] = 0;
	return (ptr);
}
/*#include <stdio.h>
char add_one(unsigned int n, char c)
{
	(void)n;
	c += 1;
	return (c);
}
int main()
{
	char str[] = "a bcdef g";
	char *result = ft_strmapi(str, add_one);
	printf("Before: %s\n", str);
	printf("After: %s", result);
	free(result);

}*/
