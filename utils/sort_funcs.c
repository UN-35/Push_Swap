/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:23:02 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/31 00:25:46 by yoelansa         ###   ########.fr       */
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
	int	size;

	size = stack_len(*stack_a);
	while (*stack_a && stack_len(*stack_a) > 3)
	{
		k = get_the_smallest(*stack_a);
		while ((*stack_a)->rank != k)
		{
			if (get_index(stack_a, k) <= size / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
		size--;
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
		while (*stack_a && _still(*stack_a, start, end) != -1)
		{
			if ((*stack_a)->rank >= start && (*stack_a)->rank <= end)
			{
				pb(stack_b, stack_a);
				if (((*stack_b)->rank < size / 2))
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
		while (*stack_a && _still(*stack_a, start, end) != -1)
		{
			if ((*stack_a)->rank >= start && (*stack_a)->rank <= end)
			{
				pb(stack_b, stack_a);
				if (((*stack_b)->rank < size / 2))
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

void	repush_to_a(t_list **a, t_list **b, int size, int j)
{
	t_list	*last_a;

	push_max(a, b, size);
	size--;
	while (*b || is_sorted(*a))
	{
		last_a = ft_lastnode(*a);
		if ((last_a->rank + 1) == (*a)->rank)
			rra(a);
		else if (*b && ((*b)->rank + 1) == (*a)->rank)
		{
			pa(a, b);
			size--;
		}
		else if (*b && (last_a->rank == j - 1 || last_a->rank < (*b)->rank))
		{
			pa(a, b);
			size--;
			ra(a);
		}
		else if (*b && get_index(b, (*a)->rank - 1) >= size / 2)
			rrb(b);
		else if (*b && get_index(b, (*a)->rank - 1) < size / 2)
			rb(b);
	}
}
