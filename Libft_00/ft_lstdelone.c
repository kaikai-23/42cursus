/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:20:31 by hkai              #+#    #+#             */
/*   Updated: 2023/10/06 16:43:14 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

////
// #include <stdio.h>

// // del関数の定義: contentを解放する
// void del(void *content)
// {
// 	free(content);
// 	content = NULL;
// }

// int main()
// {
//     t_list *node;

//     // ノードの確保と初期化
//     node = ft_lstnew(ft_strdup("Hello, World!")); // strdupは文字列をコピーして新しいメモリ領域に保存します。

//     // ノードのcontentを表示
//     printf("Before delete: %s\n", (char *)node->content);

//     // ノードの削除
//     ft_lstdelone(node, del);

//     // ここでnodeのcontentにアクセスすると、未定義の動作になるので注意してください。
//     //printf("After delete: %s\n", (char *)node->content); // これは危険です！

//     return 0;
// }