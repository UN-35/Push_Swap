/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:42:53 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/24 14:56:58 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	_error(void)
{
	write (1, "Error\n", 6);
	exit (1);
}

int	ft_str_is_digit(char *str)
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

char	*join_all(char **av)
{
	char	*tmp;
	char	*ptr;
	char	*str;
	int		i;

	str = NULL;
	i = 1;
	while (av[i])
	{
		if (!av[i][0])
			_error();
		tmp = ft_strjoin(av[i], " ");
		if (!str)
			str = ft_strdup (" ");
		ptr = str;
		str = ft_strjoin (ptr, tmp);
		free(tmp);
		free(ptr);
		i++;
	}
	return (str);
}

int	_match(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
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
	int		i;
	int		j;
	long	k;

	i = 0;
	j = 1;
	k = ft_atoi(args[0]);
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
