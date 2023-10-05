/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:21:41 by hkai              #+#    #+#             */
/*   Updated: 2023/10/05 17:32:13 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>

// int main()
// {
//     t_list *head = NULL; // リストの先頭へのポインタを初期化
//     t_list *new_node;

//     // リストに最初のノード（背番号1）を追加
//     new_node = ft_lstnew((void *)1);
//     ft_lstadd_front(&head, new_node);

//     // リストの先頭に新しいノード（背番号10）を追加
//     new_node = ft_lstnew((void *)10);
//     ft_lstadd_front(&head, new_node);

//     // リストの先頭に新しいノード（背番号20）を追加
//     new_node = ft_lstnew((void *)20);
//     ft_lstadd_front(&head, new_node);
// ///////////////////////////////////////////
// //リストのノードの最終の値を出力
// 	printf("最後のノードの中身: %d\n", (int)ft_lstlast(head)->content);
// ///////////////////////////////////////////
//     // 確認のためにリストを表示
//     t_list *current = head;
//     while (current != NULL)
//     {
//         printf("背番号: %d\n", (int)current->content);
//         current = current->next;
//     }

//     // TODO: リストのメモリを解放
//     return 0;
// }