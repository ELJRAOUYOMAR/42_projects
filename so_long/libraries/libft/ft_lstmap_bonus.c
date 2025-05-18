/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:23:49 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/06 10:31:46 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_result;
	t_list	*node;

	list_result = lst;
	if (!lst || !del || !f)
		return (NULL);
	list_result = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&list_result, del);
			return (NULL);
		}
		ft_lstadd_back(&list_result, node);
		lst = lst->next;
	}
	return (list_result);
}
/*
#include <stdio.h>
#include <string.h>
// Example function to prepend a prefix to a string (for testing)
void *add_prefix(void *content) {
    char *str = (char *)content;
    char *prefix = "Prefix_";
    
    // Allocate memory for the new string
    size_t len = ft_strlen(str) + ft_strlen(prefix) + 1;
    char *new_str = (char *)malloc(len);
    
    if (!new_str)
        return (NULL);
    
    // Combine the prefix and the original string
    strcpy(new_str, prefix);
    strcat(new_str, str);
    
    return (new_str);
}

// Example function to delete content (for cleanup)
void delete_content(void *content) {
    free(content);
}

// Function to print the list for testing
void print_list(t_list *lst) {
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list with string content
    t_list *list = NULL;
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "Test";

    // Add new nodes with strdup
    ft_lstadd_back(&list, ft_lstnew(ft_strdup(str1)));  
    ft_lstadd_back(&list, ft_lstnew(ft_strdup(str2)));  
    ft_lstadd_back(&list, ft_lstnew(ft_strdup(str3)));  

    printf("Original list:\n");
    print_list(list);

    // Apply ft_lstmap to add a prefix to each string
    t_list *mapped_list = ft_lstmap(list, add_prefix, delete_content);

    printf("\nMapped list (with prefix added):\n");
    print_list(mapped_list);

    // Clean up the lists
    ft_lstclear(&list, delete_content);
    ft_lstclear(&mapped_list, delete_content);

    return 0;
}*/
