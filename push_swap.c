/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:58:21 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/29 22:17:58 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	_sort(t_list *stack_a, t_list *stack_b)
{
	int	size;

	size = stack_len(stack_a);
	if (!is_sorted(stack_a))
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size <= 5)
		sort_five(&stack_a, &stack_b);
	else if (size <= 100)
	{
		push_chunks_b(&stack_a, &stack_b);
		repush_to_a(&stack_a, &stack_b, size, size);
	}
	else
	{
		push_big_chunks_b(&stack_a, &stack_b);
		repush_to_a(&stack_a, &stack_b, size, size);
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*string;
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;

	(void)ac;
	string = join_all(av);
	args = ft_split(string, ' ');
	if (_valid_args(args))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (args[i])
	{
		ft_add_back(&stack_a, ft_lstnew(args[i]));
		i++;
	}
	set_rank(&stack_a);
	_sort(stack_a, stack_b);
}
