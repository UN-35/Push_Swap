/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:06:27 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/24 14:58:33 by yoelansa         ###   ########.fr       */
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

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);
void	_error(void);
char	*ft_strdup(const char *src);

/*.......lst_utils......*/
t_list	*ft_prelast_node(t_list *lst);
t_list	*ft_lastnode(t_list *lst);
int		stack_len(t_list *stack);
t_list	*ft_lstnew(char *str);
void	ft_add_back(t_list **lst, t_list *node);

/*.........utils........*/
int		get_the_smallest(t_list *stack);
int		get_the_biggest(t_list *stack);
void	set_rank(t_list **stack_a, int size);
int		_still(t_list *stack_a, int start, int end);
int		found_bigrank(t_list *stack_b, int bigrank);

/*.......parsing........*/
void	_error(void);
int		ft_str_is_digit(char *str);
char	*join_all(char **av);
int		_match(char **args);
int		_valid_args(char **args);

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
