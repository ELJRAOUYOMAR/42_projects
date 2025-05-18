/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:50:01 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/05 09:53:22 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * return the lenght of a number
 * n: the number we want to calculate its lenght
 * n /= 10: for ending the loop if n = 124 it will 4 and than 2 and 1 and 0. 
*/
static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	ln;
	int		len;
	char	*result;

	ln = n;
	len = get_len(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		ln = -ln;
	}
	else if (ln == 0)
		result[0] = '0';
	while (ln > 0)
	{
		result[--len] = (ln % 10) + '0';
		ln /= 10;
	}
	return (result);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    int nbr = 4545;
    char *str = ft_itoa(nbr);
    printf("%s\n", str);
    //char *str2 = itoa(nbr);
    //printf("%s\n", str2);
    free(str);
    //free(str2);
    return 0;
}*/
