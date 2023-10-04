/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:16:11 by hkai              #+#    #+#             */
/*   Updated: 2023/10/04 16:58:01 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//必要なし
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

//ノード作成済み
//ノード間のポインタ設定必須
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;

	new->next = *lst;
	*lst = new;
}


#include <stdio.h>

int main()
{
    t_list *head = NULL; // リストの先頭へのポインタを初期化
    t_list *new_node;

    // リストに最初のノード（背番号1）を追加
    new_node = ft_lstnew((void *)1);
    ft_lstadd_front(&head, new_node);

    // リストの先頭に新しいノード（背番号10）を追加
    new_node = ft_lstnew((void *)10);
    ft_lstadd_front(&head, new_node);

    // リストの先頭に新しいノード（背番号20）を追加
    new_node = ft_lstnew((void *)20);
    ft_lstadd_front(&head, new_node);

    // 確認のためにリストを表示
    t_list *current = head;
    while (current != NULL)
    {
        printf("背番号: %d\n", (int)current->content);
        current = current->next;
    }

    // TODO: リストのメモリを解放
    return 0;
}
