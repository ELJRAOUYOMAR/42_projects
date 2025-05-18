/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:02:36 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/03 18:27:31 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
/*#include <stdio.h>
#include <stdlib.h>
int main() {
    // Create a linked list: 1 -> 2 -> 3
    t_list *head = ft_lstnew((int *)1);
    head->next = ft_lstnew((int *)2);
    head->next->next = ft_lstnew((int *)3);
    head->next->next->next = ft_lstnew((int *)4);

    // Test ft_lstsize
    int size = ft_lstsize(head);
    printf("The size of the list is: %d\n", size); // Expected output: 4

    // Free allocated memory
    t_list *current = head;
    while (current) {
        t_list *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}*/
