/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:58:21 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/24 15:31:36 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int is_sorted(t_list *stack)
{
	t_list *tmp = stack;

	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return(0);
}
int	get_index(t_list **stack, int rank)
{
	t_list *tmp = *stack;
	int i = 0;
	while (tmp)
	{
		if (tmp->rank == rank)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

////////////////// sort 3 numbers ////////////////////


void sort_three(t_list *stack)
{
	if (stack->data > stack->next->data && stack->next->next->data > stack->next->data && stack->next->next->data > stack->data)
		sa(stack);
	else if (stack->data > stack->next->next->data && stack->next->data > stack->next->next->data && stack->next->data > stack->data)
		rra(&stack);
	else if (stack->data > stack->next->data && stack->data > stack->next->next->data && stack->next->next->data > stack->next->data)
		ra(&stack);
	else if (stack->data > stack->next->data && stack->data > stack->next->next->data && stack->next->data > stack->next->next->data)
	{
		sa(stack);
		rra(&stack);
	}
	else if (stack->next->data > stack->data && stack->next->next->data > stack->data && stack->next->data > stack->next->next->data)
	{
		sa(stack);
		ra(&stack);
	}
}


////////////////////// sort 5 numbers ////////////////
void sort_five(t_list **stack_a, t_list **stack_b)
{
	int k;

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

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*stack_a) || !(*stack_a)->next || !(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lastnode(tmp)->next = *stack_a;
	*stack_a = tmp;

	tmp2 = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lastnode(tmp2)->next = *stack_b;
	*stack_b = tmp2;
	write(1, "rr\n", 3);
}



void	push_chunks_b(t_list **stack_a, t_list **stack_b)
{
	int size = stack_len(*stack_a);
	int start = (size / 2) - 10;
	int end = (size / 2) + 10;
	int i = 0;

	while (*stack_a && i < size)
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
		start -= 10;
		end += 10;
		i++;
	}
}

void	push_big_chunks_b(t_list **stack_a, t_list **stack_b)
{
	int size = stack_len(*stack_a);
	int start = (size / 2) - 29;
	int end = (size / 2) + 29;
	int i = 0;

	while (*stack_a && i < size)
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
		i++;
	}
}



void	push_max(t_list **stack_a, t_list **stack_b, int size)
{
	t_list *tmp = *stack_b;
	int i = 0;

	while (tmp)
	{
		if (tmp->rank == size)
			break;
		i++;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	if (i  > size / 2)
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


void	repush_to_a(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*last_a;
	push_max(stack_a, stack_b, size);
	int j = size;
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
		else if (*stack_b && (last_a->rank == j - 1 || last_a->rank < (*stack_b)->rank))
		{
			pa(stack_a, stack_b);
			size--;
			ra(stack_a);
		}
		else if (*stack_b && get_index(stack_b, (*stack_a)->rank - 1) >= size / 2)
			rrb(stack_b);
		else if (*stack_b && get_index(stack_b, (*stack_a)->rank - 1) < size / 2)
			rb(stack_b);
	}
}

int main(int ac, char **av)
{
	char *string;
	char **args;
	(void)ac;
	if (ac < 2)
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
	if (size <= 100)
		push_chunks_b(&stack_a, &stack_b);
	else
		push_big_chunks_b(&stack_a, &stack_b);
	repush_to_a(&stack_a, &stack_b, size);
	// pb (&stack_b, &stack_a);
	// pb (&stack_b, &stack_a);
	// // rr(&stack_a, &stack_b);
	// printf("A: %d\n", stack_a->data);
	// printf("A: %d\n", stack_a->next->data);
	// printf("B: %d\n", stack_b->data);
	// printf("B: %d\n", stack_b->next->data);
}
