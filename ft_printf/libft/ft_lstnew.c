/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:23:11 by hkai              #+#    #+#             */
/*   Updated: 2023/10/04 15:54:54 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//わかりやすくするために宣言を入れておく
//本来は必要ない
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list) * 1);
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// #include <stdio.h>

// int	main(void)
// {
//     t_list *new_node;
//     char *content = "Hello";

//     // ft_lstnew関数をテスト
//     new_node = ft_lstnew(content);

//     if (new_node == NULL)
//     {
//         printf("メモリ確保失敗\n");
//         return (1);
//     }

//     printf("出力してほしいcontent: %s\n", content);
//     printf("content: %s\n", (char *)new_node->content);

//     if (new_node->next != NULL)
//         printf("nextにNULLが設定されていない\n");
//     else
//         printf("nextにNULLが設定されている\n");

//     // メモリのクリーンアップ
//     free(new_node);
// 	printf("\n");
// /////////////////////////////////////////
//     t_list *new_node2;
//     int number = 23;

//     // ft_lstnew関数をテスト
//     new_node2 = ft_lstnew(&number);
//     if (new_node2 == NULL)
//     {
//         printf("メモリ確保失敗\n");
//         return (1);
//     }
// 	int *setting_number = new_node2->content;
//     printf("出力してほしいcontent: %d\n", number);
//     printf("content: %d\n", *setting_number);

//     if (new_node2->next != NULL)
//         printf("nextにNULLが設定されていない\n");
//     else
//         printf("nextにNULLが設定されている\n");

//     // メモリのクリーンアップ
//     free(new_node2);
//     return (0);
// }
