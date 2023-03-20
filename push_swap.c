/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:58:21 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/20 13:43:49 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	_error(void)
{
	write (1, "Error\n", 6);
	exit (1);
}

int ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char *join_all(char **av)
{
	char *tmp;
	char *ptr;
	char *str=  NULL;
	int i = 1;
	while (av[i])
	{
		if (!av[i][0])
			_error();
		tmp = ft_strjoin(av[i] , " ");
		if (!str)
			str = ft_strdup(" ");
		ptr = str;
		str = ft_strjoin (ptr, tmp);
		free(tmp);
		free(ptr);
		i++;
	}
	return (str);
}

int _match(char **args)
{
	int i = 0;
	int j = 1;
	while (args[i] && i < j)
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	return (0);
}

int	_valid_args(char **args)
{
	int i = 0;
	int j = 1;
	long k = ft_atoi(args[0]);
	if (k > INT_MAX || k < INT_MIN)
		_error();
	while (args[i])
	{
		j = 0;
		if (!args[i][0])
			_error();
		if (*args[i] == '+' || *args[i] == '-')
		{
			j = 1;
			if (!args[i][j])
				_error();
		}
		if (ft_str_is_digit(args[i] + j) == 1)
			_error();
		i++;
	}
	if (_match(args))
		_error();
	return (0);
}



///////////////////////////////commands///////////////////////////////

////// swap swap

void	ss(t_list *stack_a, t_list *stack_b)
{
	int	tmp;

	if (stack_a->next)
	{
		tmp = stack_a->data;
		stack_a->data = stack_a->next->data;
		stack_a->next->data = tmp;
	}
	tmp = 0;
	if (stack_b->next)
	{
		tmp = stack_b->data;
		stack_b->data = stack_b->next->data;
		stack_b->next->data = tmp;
	}
}


//////////reverse rotation//////

void rra(t_list **stack_a)
{
	t_list *tmp;

	if (!(*stack_a)->next)
		return ;
	tmp = ft_lastnode(*stack_a);
	ft_prelast_node(*stack_a)->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void rrb(t_list **stack_b)
{
	t_list *tmp;

	if (!(*stack_b)->next)
		return ;
	tmp = ft_lastnode(*stack_b);
	ft_prelast_node(*stack_b)->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
}

//////////rotation///////

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lastnode(tmp)->next = *stack_a;
	*stack_a = tmp;
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
}



////////////////// sort 3 numbers ////////////////////


void sort_three(t_list *stack)
{
	if (stack->data > stack->next->data && stack->next->next->data > stack->next->data && stack->next->next->data > stack->data)
	{
		sa(stack);
		// write(1, "sa\n", 3);
	}
	else if (stack->data > stack->next->next->data && stack->next->data > stack->next->next->data && stack->next->data > stack->data)
	{
		rra(&stack);
		// write(1, "rra\n", 4);
	}
	else if (stack->data > stack->next->data && stack->data > stack->next->next->data && stack->next->next->data > stack->next->data)
	{
		ra(&stack);
		// write(1, "ra\n", 3);
	}
	else if (stack->data > stack->next->data && stack->data > stack->next->next->data && stack->next->data > stack->next->next->data)
	{
		sa(stack);
		rra(&stack);
		// write(1, "sa\nrra\n", 8);
	}
	else if (stack->next->data > stack->data && stack->next->next->data > stack->data && stack->next->data > stack->next->next->data)
	{
		sa(stack);
		ra(&stack);
		// write(1, "sa\nra\n", 7);
	}
}

////////////////////// sort 5 numbers ////////////////

int get_the_smallest(t_list *stack)
{
	int min;
	min = stack->data;

	while(stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
	// int i = 0;
	int k;

	while (*stack_a && stack_len(*stack_a) > 3)
	{
		k = get_the_smallest(*stack_a);
		while ((*stack_a)->data != k)
			ra(stack_a);
		pb(stack_b, stack_a);
		// (*stack_a)->data = (*stack_a)->next->data;
	}
	sort_three(*stack_a);
	// while (*stack_b)
	// {
	// 	// write(1, "hna\n", 4);
	// 	pa(stack_a, stack_b);
	// }
}



int main(int ac, char **av)
{
	char *string;
	char **args;
	if (ac < 2)
		return(0);
	string = join_all(av);
	args = ft_split(string , ' ');
	if (_valid_args(args))
		exit (1);
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	int i = 0;
	while (args[i])
	{
		ft_add_back(&stack_a, ft_lstnew(args[i]));
		i++;
	}
	pb(&stack_b, &stack_a);
	pb(&stack_b, &stack_a);
	ss(stack_a, stack_b);
	printf ("head of stack_A : %d\n", stack_a->data);
	printf ("next of stack_A : %d\n", stack_a->next->data);
	printf ("\n\nhead of stack_B : %d\n", stack_b->data);
	printf ("next of stack_B : %d\n", stack_b->next->data);
	
}
