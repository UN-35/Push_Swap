/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:06:27 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/20 12:55:12 by yoelansa         ###   ########.fr       */
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
	struct s_list	*next;
} t_list;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);
void	_error(void);
char	*ft_strdup(const char *src);

/////////lst_utils///////
t_list	*ft_prelast_node(t_list *lst);
t_list	*ft_lastnode(t_list *lst);
int		stack_len(t_list *stack);
t_list	*ft_lstnew(char *str);
void	ft_add_back(t_list **lst, t_list *node);

////////CMDs//////////
/*  swap  */
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);

/*  push  */
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);


#endif

/*
valid args
initialize
instructions
sort
*/