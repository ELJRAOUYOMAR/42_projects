/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:13:42 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/06 11:39:17 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * nmemb: number of elements allocate.
 * size: The size of each element.	
 * If either nmemb or size is a large number,
 * multiplying them could overflow the size_t data type.
 * This overflow could result in a negative value or an unexpected result.
 * */	

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
