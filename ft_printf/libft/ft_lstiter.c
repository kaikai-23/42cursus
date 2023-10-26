/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:46:01 by hkai              #+#    #+#             */
/*   Updated: 2023/10/06 17:26:36 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

///
// #include "libft.h"
// #include <stdio.h>
// #include <ctype.h>  // for toupper function

// // Function to convert a string to uppercase
// void	to_uppercase(void *content)
// {
// 	char *str = (char *)content;
// 	while (*str)
// 	{
// 		*str = ft_toupper(*str);
// 		str++;
// 	}
// }



// 	// // del関数の定義: contentを解放する
// 	void del(void *content)
// 	{
// 		free(content);
// 		// content = NULL;
// 	}

// int main()
// {
//     t_list *head = ft_lstnew(ft_strdup("Hello"));
// 	t_list *node1 = ft_lstnew(ft_strdup("world"));
// 	t_list *node2 = ft_lstnew(ft_strdup("from"));
// 	t_list *node3 = ft_lstnew(ft_strdup("libft"));

// 	head->next = node1;
// 	node1->next = node2;
// 	node2->next = node3;

//     // Before applying the function
//     printf("関数に代入前のノードの中身:\n");
//     t_list *tmp = head;
//     while (tmp)
//     {
//         printf("%s\n", (char *)tmp->content);
//         tmp = tmp->next;
//     }

//     // Applying ft_lstiter
//     ft_lstiter(head, to_uppercase);

//     // After applying the function
//     printf("\n関数代入後:\n");
//     tmp = head;
//     while (tmp)
//     {
//         printf("%s\n", (char *)tmp->content);
//         tmp = tmp->next;
//     }

//     // TODO: Free the memory for the list and its content	
// 	t_list *next_tmp;
// 	tmp = head;
// 	while (tmp)
// 	{
// 		next_tmp = tmp->next;
// 		ft_lstdelone(tmp,del);
// 		tmp = next_tmp;
// 		// free(tmp->content);
// 		// next_tmp = tmp->next;
// 		// free(tmp);
// 		// tmp = next_tmp;
// 	}
//     return (0);
// }
