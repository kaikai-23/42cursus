/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:28:32 by hkai              #+#    #+#             */
/*   Updated: 2023/10/06 20:58:59 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

// void del(void *content)
// {
// 	free(content);
// }

// #include <stdio.h>

// int main()
// {
//     t_list *head = ft_lstnew(ft_strdup("Hello"));
// 	t_list *node1 = ft_lstnew(ft_strdup("world"));
// 	t_list *node2 = ft_lstnew(ft_strdup("from"));
// 	t_list *node3 = ft_lstnew(ft_strdup("libft"));

// 	head->next = node1;
// 	node1->next = node2;
// 	node2->next = node3;

//     // Before clearing the list
//     printf("リストの削除処理前:\n");
//     t_list *tmp = head;
//     while (tmp)
//     {
//         printf("%s\n", (char *)tmp->content);
//         tmp = tmp->next;
//     }

//     // Clearing the list
//     ft_lstclear(&head, del);

//     // After clearing the list
//     printf("\n削除処理後:\n");
//     if (head == NULL)
//     {
//         printf("リスト削除完了。\n");
//     }
//     else
//     {
//         printf("リスト削除失敗\n");
//     }

//     return 0;
// }