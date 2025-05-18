/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:09:50 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/03 11:08:23 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*created_node;

	created_node = (t_list *)malloc(sizeof(t_list));
	if (!created_node)
		return (NULL);
	created_node->content = content;
	created_node->next = NULL;
	return (created_node);
}
/*#include <stdio.h>
#include <stdlib.h>
int main() {
    // Test 1: Create a new node
    int value = 42;
    int other_value = 100;
    t_list *node = ft_lstnew(&value);

    // Check if node is not NULL
    if (node == NULL) {
        printf("Test failed: Node is NULL\n");
        return 1;
    }

    // Check if content is set correctly
    if (*(int *)(node->content) != value) {
        printf("Test failed: Content is incorrect\n");
        free(node);
        return 1;
    } else {
        printf("Test passed: Content is correct\n");
    }

    // Check if next is NULL
    if (node->next != NULL) {
        printf("Test failed: Next pointer is not NULL\n");
    } else {
        printf("Test passed: Next pointer is NULL\n");
    }

    // Free the allocated node
    free(node);

    return 0;
}*/
