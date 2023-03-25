/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:06:27 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/25 01:29:31 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int data;
	int	rank;
	struct s_list	*next;
} t_list;
/*......libft_funcs....*/
void	_error(void);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

/*.......lst_utils......*/
t_list	*ft_lstnew(char *str);
int		stack_len(t_list *stack);
t_list	*ft_lastnode(t_list *lst);
t_list	*ft_prelast_node(t_list *lst);
void	ft_add_back(t_list **lst, t_list *node);

/*.........utils........*/
int		get_the_biggest(t_list *stack);
int		get_the_smallest(t_list *stack);
void	set_rank(t_list **stack_a, int size);
int		_still(t_list *stack_a, int start, int end);
int		found_bigrank(t_list *stack_b, int bigrank);
//more:
int		is_sorted(t_list *stack);
int		get_index(t_list **stack, int rank);
void	push_max(t_list **stack_a, t_list **stack_b, int size);

/*.......parsing........*/
void	_error(void);
int		_match(char **args);
char	*join_all(char **av);
int		_valid_args(char **args);
int		ft_str_is_digit(char *str);

/*......main_sort......*/
void    sort_three(t_list *stack);
void    sort_five(t_list **stack_a, t_list **stack_b);
void	push_chunks_b(t_list **stack_a, t_list **stack_b);
void	push_big_chunks_b(t_list **stack_a, t_list **stack_b);
void	repush_to_a(t_list **stack_a, t_list **stack_b, int size);

/*.........CMDs.........*/
/*  swap  */
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);

/*  push  */
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);

/*  rotation  */
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);


#endif
