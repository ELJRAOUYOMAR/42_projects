/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:41:59 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/05 11:38:24 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}
/*
void delete_content(void *content) {
    free(content); // Assuming content was dynamically allocated
}
#include <stdio.h>
int main() {
    // Create and initialize a new list node
    t_list *node = malloc(sizeof(t_list));
    node->content = malloc(20);
    sprintf((char *)node->content, "Hello!");

    // Output the content before deletion
    printf("Before deletion: %s\n", (char *)node->content);

    // Delete the node
    ft_lstdelone(node, delete_content);

    //printf("after deletion: %s\n", (char *)node->content);
    // Indicate completion
    printf("Node has been deleted.\n");

    return 0;
}
*/
