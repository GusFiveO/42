/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:42:23 by alorain           #+#    #+#             */
/*   Updated: 2021/11/25 15:24:32 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*elem;
	t_list	**new;
	
	new = &elem;
	temp = lst;
	while (temp != NULL)
	{
		(*f)(temp->content);
		elem = ft_lstnew(temp->content);
		if (!elem)
			ft_lstclear(new, (*del));
		temp = temp->next;
	}
	return (*new);
}
