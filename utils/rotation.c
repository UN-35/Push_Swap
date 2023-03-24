/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:15:37 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/24 03:56:37 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*  rotation    */

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lastnode(tmp)->next = *stack_a;
	*stack_a = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lastnode(tmp)->next = *stack_b;
	*stack_b = tmp;
	write(1, "rb\n", 3);
}

/*  reverse  */

void	rra(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a)->next)
		return ;
	tmp = ft_lastnode(*stack_a);
	ft_prelast_node(*stack_a)->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b)->next)
		return ;
	tmp = ft_lastnode(*stack_b);
	ft_prelast_node(*stack_b)->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "rrb\n", 4);
}
