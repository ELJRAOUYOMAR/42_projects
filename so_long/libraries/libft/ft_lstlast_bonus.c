/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:41:19 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/05 10:38:25 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * other while loop fot the temp_list
 	while (tmp)
        {
                if (tmp->next == NULL)
                        return tmp;
                tmp = tmp->next;
        }
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp_list;

	temp_list = lst;
	if (!temp_list)
		return (NULL);
	while (temp_list->next)
	{
		temp_list = temp_list->next;
	}
	return (temp_list);
}
/*
#include <stdio.h>
#include <stdlib.h>
void free_list(t_list *lst) {
    t_list *temp;
    while (lst) {
        temp = lst;
        lst = lst->next;
        free(temp);
    }
}

int main() {
    // Create a linked list with 3 nodes
    t_list *head = ft_lstnew("Node 1");
    head->next = ft_lstnew("Node 2");
    head->next->next = ft_lstnew("Node 3");

    // Get the last node
    t_list *last_node = ft_lstlast(head);

    // Print the content of the last node
    if (last_node) {
        printf("Last node content: %s\n", (char *)last_node->content);
    } else {
        printf("The list is empty.\n");
    }

    // Free the list
    free_list(head);

    return 0;
}
*/
