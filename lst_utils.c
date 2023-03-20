/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:46:55 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/20 12:47:18 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_prelast_node(t_list *lst)
{
	if (!lst || !lst->next)
		return (lst);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lastnode(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	stack_len(t_list *stack)
{
	int j = 0;
	while (stack)
	{
		stack = stack->next;
		j++;
	}
	return (j);
}


t_list	*ft_lstnew(char *str)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = ft_atoi(str);
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_list **lst, t_list *node)
{
	if (*lst)
		ft_lastnode(*lst)->next = node;
	else
		*lst = node;
}