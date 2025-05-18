/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:09:13 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/05 11:01:21 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * the if statement if there is nothing in the list, 
 * we set the list pointer points to the new.
 * Otherwise, find the last node and append the new node
 * 
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
#include <stdio.h>
void ft_lstprint(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *((int *)lst->content));
        lst = lst->next;
    }
    printf("NULL\n");
}

void del(void *content) {
    free(content);
}


// Function to free the list (to avoid memory leaks)
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst)
		return ;
	while (*lst)
	{	
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	*lst = NULL;
}
int main(void)
{
    // Test: Create a list and add nodes to it
    t_list *head = NULL;

    // Add nodes to the list using ft_lstadd_back
    int *content1 = malloc(sizeof(int));
    *content1 = 10;
    ft_lstadd_back(&head, ft_lstnew(content1));  // Add 10

    int *content2 = malloc(sizeof(int));
    *content2 = 20;
    ft_lstadd_back(&head, ft_lstnew(content2));  // Add 20

    int *content3 = malloc(sizeof(int));
    *content3 = 30;
    ft_lstadd_back(&head, ft_lstnew(content3));  // Add 30

    // Print the list
    printf("List after adding nodes:\n");
    ft_lstprint(head); 10 -> 20 -> 30 -> NULL

    // Add more nodes to test further
    int *content4 = malloc(sizeof(int));
    *content4 = 40;
    ft_lstadd_back(&head, ft_lstnew(content4));  // Add 40

    int *content5 = malloc(sizeof(int));
    *content5 = 50;
    ft_lstadd_back(&head, ft_lstnew(content5));  // Add 50

    // Print the updated list
    printf("List after adding more nodes:\n");
    ft_lstprint(head);  // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    // Clean up memory
    ft_lstclear(&head, del);
    return 0;
}*/
