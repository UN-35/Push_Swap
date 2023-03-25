/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:58:21 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/25 18:19:58 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	rr(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;
// 	t_list	*tmp2;

// 	if (!(*stack_a) || !(*stack_a)->next || !(*stack_b) || !(*stack_b)->next)
// 		return ;
// 	tmp = (*stack_a)->next;
// 	(*stack_a)->next = NULL;
// 	ft_lastnode(tmp)->next = *stack_a;
// 	*stack_a = tmp;

// 	tmp2 = (*stack_b)->next;
// 	(*stack_b)->next = NULL;
// 	ft_lastnode(tmp2)->next = *stack_b;
// 	*stack_b = tmp2;
// 	write(1, "rr\n", 3);
// }

int main(int ac, char **av)
{
	char	*string;
	char	**args;

	if (ac <= 2)
		return(0);
	string = join_all(av);
	args = ft_split(string , ' ');
	if (_valid_args(args))
		exit (1);
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	int i = 0;
	int size;
	while (args[i])
	{
		ft_add_back(&stack_a, ft_lstnew(args[i]));
		i++;
	}
	size = stack_len(stack_a);
	set_rank(&stack_a, size);
	if (size == 2)
	{
		if (!is_sorted(stack_a))
			return (0);
		sa(stack_a);
	}
	else if (size <= 5)
		sort_five(&stack_a, &stack_b);
	else if (size <= 100)
	{
		push_chunks_b(&stack_a, &stack_b);
		repush_to_a(&stack_a, &stack_b, size);
	}
	else
	{
		push_big_chunks_b(&stack_a, &stack_b);
		repush_to_a(&stack_a, &stack_b, size);
	}
}
