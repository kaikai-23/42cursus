/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:27:43 by hkai              #+#    #+#             */
/*   Updated: 2023/10/06 21:15:28 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	// t_list	*store_head;
	// int		i;

	// i = 0;
	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		//新しいノードを作成し、関数fを適用
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			// エラーが発生した場合,すべてのノードを解放します
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		// if (i == 0)
		// 	store_head = new_node;
		ft_lstadd_back(&new_lst, new_node);
		// i++;
		lst = lst->next;
	}
	return (new_lst);
}

// void	*to_uppercase(void *content)
// {
// 	char	*str;
// 	char	*new_str;
// 	int		i;

// 	str = (char *)content;
// 	new_str = ft_strdup(str);
// 	if (!new_str)
// 		return (NULL);
// 	i = 0;
// 	while (new_str[i])
// 	{
// 		new_str[i] = ft_toupper(new_str[i]);
// 		i++;
// 	}
// 	return (new_str);
// }

// #include <stdio.h>

// int main()
// {
//     t_list *head = ft_lstnew(ft_strdup("hello"));
// 	t_list *node1 = ft_lstnew(ft_strdup("world"));
// 	t_list *node2 = ft_lstnew(ft_strdup("from"));
// 	t_list *node3 = ft_lstnew(ft_strdup("libft"));

// 	head->next = node1;
// 	node1->next = node2;
// 	node2->next = node3;

//     // Before applying the function
//     printf("関数適用前のリスト:\n");
//     t_list *tmp = head;
//     while (tmp)
//     {
//         printf("%s\n", (char *)tmp->content);
//         tmp = tmp->next;
//     }

//     t_list *new_head = ft_lstmap(head, to_uppercase, free);

//     // After applying the function
//     printf("\n関数適用後の新しいリスト:\n");
//     tmp = new_head;
//     while (tmp)
//     {
//         printf("%s\n", (char *)tmp->content);
//         tmp = tmp->next;
//     }

//     // メモリを解放
//     ft_lstclear(&head, free);
//     ft_lstclear(&new_head, free);
//     return 0;
// }
