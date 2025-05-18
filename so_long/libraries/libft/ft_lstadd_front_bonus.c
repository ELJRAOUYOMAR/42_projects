/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:40:40 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/03 17:47:42 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>
void print_list(t_list *lst) {
    while (lst != NULL) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main() {
    t_list *head = NULL; // Start with an empty list

    // Create some nodes
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    // Add nodes to the front of the list
    ft_lstadd_front(&head, node1); // List: Node 1
    ft_lstadd_front(&head, node2); // List: Node 2 -> Node 1
    ft_lstadd_front(&head, node3); // List: Node 3 -> Node 2 -> Node 1

    // Print the list to verify
    print_list(head);

    // Free allocated memory (optional but good practice)
    t_list *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}*/
