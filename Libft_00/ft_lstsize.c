/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:53:29 by hkai              #+#    #+#             */
/*   Updated: 2023/10/05 17:17:54 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ノードそのもののアドレスft_lstadd_frontのlstとは別で考える必要がある。
//ノードがいくつあるかを数えている
//最初のノードのポインタがきてるのでnextで更新し続けてNULLの場所を見つける
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		//アドレスを直接受け渡し
		lst = lst->next;
	}
	return (size);
}

#include <stdio.h>

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
// //リストのノードの個数を数える
// 	printf("ノードの個数: %d\n", ft_lstsize(head));
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