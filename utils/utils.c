/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:40:28 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/31 16:33:18 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	get_the_smallest(t_list *stack)
{
	int		min;
	t_list	*tmp;

	min = stack->data;
	tmp = stack;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (tmp->data == min)
			return (tmp->rank);
		tmp = tmp->next;
	}
	return (-1);
}

int	get_the_biggest(t_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max && stack->rank == 0)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

void	set_rank(t_list **stack_a)
{
	int		j;
	int		size;
	t_list	*tmp;

	size = stack_len(*stack_a);
	j = get_the_biggest(*stack_a);
	tmp = *stack_a;
	while (size > 0)
	{
		tmp = *stack_a;
		j = get_the_biggest(*stack_a);
		while (tmp)
		{
			if (tmp->data == j)
				tmp->rank = size;
			tmp = tmp->next;
		}
		size--;
	}
}

int	_still(t_list *stack_a, int start, int end)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->rank >= start && stack_a->rank <= end)
			return (i);
		i++;
		stack_a = stack_a->next;
	}
	return (-1);
}

int	found_bigrank(t_list *stack_b, int bigrank)
{
	while (stack_b)
	{
		if (stack_b->rank == bigrank)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}
