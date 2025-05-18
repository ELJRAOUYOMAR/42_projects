/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:20:21 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/06 22:00:12 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * free the substrings and the string itself
 * this function for the leeks of data, and non memory allocation,
 * if the second substring doesn't allocated we need to free
 * all the previous substring and the string itself
 * 
 * assign_substr: extracts a substring from
 *  the string s and assigns it to the ptr array at index *index
 *
 * **str: the string we need to free
 * sub_index: the index of each substring in the string
 */
static size_t	get_str_count(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static void	**free_str(char **str, size_t sub_index)
{
	while (sub_index > 0)
	{
		free(str[--sub_index]);
	}
	free(str);
	return (NULL);
}

static int	assign_substr(char **ptr, const char *s,
		size_t *index, char c)
{
	size_t		len;
	const char	*start;

	start = s;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	ptr[*index] = ft_substr(start, 0, len);
	if (!ptr[(*index)++])
	{
		free_str(ptr, *index - 1);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**ptr;
	int		result;

	ptr = (char **)malloc(sizeof(char *) * (get_str_count(s, c) + 1));
	if (!ptr)
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		result = assign_substr(ptr, s, &index, c);
		if (!result)
		{
			free_str(ptr, index);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
	}
	ptr[index] = NULL;
	return (ptr);
}
/*
#include <stdio.h>

void print_words(char **words) {
    if (!words) {
        printf("NULL\n");
        return;
    }
    for (size_t i = 0; words[i] != NULL; i++) {
        printf("Word[%zu]: %s\n", i, words[i]);
    }
}

static int      allocate_memory(char ***ptr, size_t count)
{
        *ptr = malloc(sizeof(char *) * count);
        return (*ptr == NULL);
}

int main() {
    const char *test_string = "Hello World, this is a test!";
    char delimiter = ' ';

    // Call the ft_split function
    char **result = ft_split(test_string, delimiter);

    // Print the results
    print_words(result);

    // Free the allocated memory
    if (result) {
        for (size_t i = 0; result[i] != NULL; i++) {
            free(result[i]); // Free each substring
        }
        free(result); // Free the array of strings
    }

    return 0;
}*/
