/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:17:28 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/25 17:45:33 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	get_index(t_list **stack, int rank)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->rank == rank)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	push_max(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->rank == size)
			break ;
		i++;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	if (i > size / 2)
	{
		while ((*stack_b)->rank != size)
			rrb(stack_b);
	}
	else
	{
		while ((*stack_b)->rank != size)
			rb(stack_b);
	}
	pa(stack_a, stack_b);
}
