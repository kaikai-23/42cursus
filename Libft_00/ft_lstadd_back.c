/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:38 by hkai              #+#    #+#             */
/*   Updated: 2023/10/07 15:07:50 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//debug
// #include <stdio.h>

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode_point;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		//後ろにもノードが続いているnewが入る可能性があるからヌルにしてはいけない
		// new->next = NULL;
		return ;
	}
	lastnode_point = ft_lstlast(*lst);
	lastnode_point->next = new;
	//後ろにもノードが続いているnewが入る可能性があるからヌルにしてはいけない
	// new->next = NULL;


	//ノードはそもそも別のメモリに保存されているものを
	//nextで繋いでるので配列なような使い方はできない
	// int	size;
	// size = ft_lstsize(lst[0]);
	// (lst[size - 1])->next = new;
	// new->next = NULL;
}

// #include <stdio.h>

// int main()
// {
//     t_list *head = ft_lstnew((void *)0); // リストの最初へのポインタを初期化
//     t_list *new_node;

//     // リストに最初のノード（背番号1）を追加
//     nenw_ode = ft_lstnew((void *)1);
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