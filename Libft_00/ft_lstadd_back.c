/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:38 by hkai              #+#    #+#             */
/*   Updated: 2023/10/05 19:14:02 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//debug
#include <stdio.h>

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	int	size;

	if (lst[0] == NULL)
		lst[0] = new;
	size = ft_lstsize(lst[0]);
	(lst[size - 1])->next = new;
	new->next = NULL;
}

#include <stdio.h>

int main()
{
    t_list *head = ft_lstnew((void *)0); // リストの最初へのポインタを初期化
	t_list *save = head;
    t_list *new_node;

	//最初のヘッドの状態
	printf("最初のヘッド :%p\n", head);
	head++;
    // リストに最初のノード（背番号1）を追加
    new_node = ft_lstnew((void *)1);
    ft_lstadd_back(&head, new_node);
	//debug
	// printf("追加後最初ノードのアドレス :%p\n", head);
	// printf("リスト0のアドレス :%p\n", head);
	// printf("head中身: %d\n", (int)head->content);
	// printf("リスト0の中身: %d\n", (int)head->content);
	// printf("リスト0の次のノード :%p\n", head->next);

    // //リストの最後に新しいノード（背番号10）を追加
    new_node = ft_lstnew((void *)10);
    ft_lstadd_back(&head, new_node);
	head++;
	//debug
	// printf("追加後最初のノード :%p\n", head);
	// printf("リスト1のアドレス :%p\n", head->next);
	// printf("head中身: %d\n", (int)head->content);
	// printf("リスト1の中身: %d\n", (int)head->next->content);
	// printf("リスト1の次のノード :%p\n", head->next->next);

    // リストの最後に新しいノード（背番号10）を追加
    new_node = ft_lstnew((void *)20);
    ft_lstadd_back(&head, new_node);

    // 確認のためにリストを表示
    // t_list *current = save;
	int i = 0;
    while (save != NULL)
    {
        printf("背番号: %d\n", (int)save->content);
		printf("次のノード: %p\n", save->next);
        save = save->next;
		i++;
    }

	// t_list *current = head;
	// int i = 0;
    // while (i < 1)
    // {
    //     printf("背番号: %d\n", (int)current->content);
    //     current = current->next;
	// 	i++;
    // }

    // TODO: リストのメモリを解放
    return 0;
}