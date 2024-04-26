/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:48:21 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/05 16:10:20 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*temp;
	t_list	*to_add;

	new_list = NULL;
	while (lst != NULL)
	{
		temp = (f)(lst->content);
		if (temp == NULL)
			return (ft_lstclear(&new_list, del), NULL);
		else
		{
			to_add = ft_lstnew(temp);
			if (to_add == NULL)
			{
				(del)(temp);
				return (ft_lstclear(&new_list, del), NULL);
			}
			ft_lstadd_back(&new_list, to_add);
		}
		lst = lst->next;
	}
	return (new_list);
}
