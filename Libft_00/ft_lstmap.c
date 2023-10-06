/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:27:43 by hkai              #+#    #+#             */
/*   Updated: 2023/10/06 20:28:05 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_lst;
	t_list	*new_node;
	t_list	*store_head;
	// int		i;

	// i = 0;
	if (!lst || !f || !del)
		return (NULL);
	*new_lst = NULL;
	while (lst != NULL)
	{
		//新しいノードを作成し、関数fを適用
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			// エラーが発生した場合,すべてのノードを解放します
			ft_lstclear(new_lst, del);
			return (NULL);
		}
		// if (i == 0)
		// 	store_head = new_node;
		ft_lstadd_back(new_lst, new_node);
		// i++;
		lst = lst->next;
	}
	return (*new_lst);
}

// #include <stdio.h>

// int main()
// {
// // リストの最初へのポインタを初期化
//     t_list *head = ft_lstnew((void *)0);
//     t_list *new_node;

//     // リストに最初のノード（背番号1）を追加
//     new_node = ft_lstnew((void *)1);
//     ft_lstadd_back(&head, new_node);

//     // リストの最後に新しいノード（背番号10）を追加
//     new_node = ft_lstnew((void *)10);
//     ft_lstadd_back(&head, new_node);

//     // リストの最後に新しいノード（背番号20）を追加
//     new_node = ft_lstnew((void *)20);
//     ft_lstadd_back(&head, new_node);

//     // 確認のためにリストを表示
//     t_list *current = head;
//     while (current != NULL)
//     {
//         printf("背番号: %d\n", (int)current->content);
//         printf("次のノード: %p\n", current->next);
//         current = current->next;
//     }

//     // TODO: リストのメモリを解放
//     return 0;
// }