/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:23:02 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/25 18:22:25 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*........sort 3 numbers........*/

void	sort_three(t_list *stack)
{
	int	h;
	int	j;
	int	k;

	h = stack->data;
	j = stack->next->data;
	k = stack->next->next->data;
	if (h > j && k > j && k > h)
		sa(stack);
	else if (h > k && j > k && j > h)
		rra(&stack);
	else if (h > j && h > k && k > j)
		ra(&stack);
	else if (h > j && h > k && j > k)
	{
		sa(stack);
		rra(&stack);
	}
	else if (j > h && k > h && j > k)
	{
		sa(stack);
		ra(&stack);
	}
}

/*........sort 5 numbers........*/

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	k;

	while (*stack_a && stack_len(*stack_a) > 3)
	{
		k = get_the_smallest(*stack_a);
		while ((*stack_a)->data != k)
			ra(stack_a);
		pb(stack_b, stack_a);
	}
	sort_three(*stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

/*........under a 100 number........*/

void	push_chunks_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	start;
	int	end;

	size = stack_len(*stack_a);
	start = (size / 2) - 15;
	end = (size / 2) + 15;
	while (*stack_a)
	{
		while (*stack_a && _still(*stack_a, start, end) == 1)
		{
			if ((*stack_a)->rank >= start && (*stack_a)->rank <= end)
			{
				pb(stack_b, stack_a);
				if ((*stack_b)->rank < size / 2)
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		start -= 15;
		end += 15;
	}
}

/*........under 500 number........*/

void	push_big_chunks_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	start;
	int	end;

	size = stack_len(*stack_a);
	start = (size / 2) - 29;
	end = (size / 2) + 29;
	while (*stack_a)
	{
		while (*stack_a && _still(*stack_a, start, end) == 1)
		{
			if ((*stack_a)->rank >= start && (*stack_a)->rank <= end)
			{
				pb(stack_b, stack_a);
				if ((*stack_b)->rank < size / 2)
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		start -= 29;
		end += 29;
	}
}

/*.....push back from b to a.....*/

void	repush_to_a(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*last_a;
	int		j;

	push_max(stack_a, stack_b, size);
	j = size;
	size--;
	while (*stack_b || is_sorted(*stack_a))
	{
		last_a = ft_lastnode(*stack_a);
		if ((last_a->rank + 1) == (*stack_a)->rank)
			rra(stack_a);
		else if (*stack_b && ((*stack_b)->rank + 1) == (*stack_a)->rank)
		{
			pa(stack_a, stack_b);
			size--;
		}
		else if (*stack_b
			&& (last_a->rank == j - 1 || last_a->rank < (*stack_b)->rank))
		{
			pa(stack_a, stack_b);
			size--;
			ra(stack_a);
		}
		else if (*stack_b
			&& get_index(stack_b, (*stack_a)->rank - 1) >= size / 2)
			rrb(stack_b);
		else if (*stack_b
			&& get_index(stack_b, (*stack_a)->rank - 1) < size / 2)
			rb(stack_b);
	}
}
