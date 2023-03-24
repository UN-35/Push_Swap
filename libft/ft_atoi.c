/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:43:14 by yoelansa          #+#    #+#             */
/*   Updated: 2023/03/24 04:13:04 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_err(int a, unsigned long r)
{
	if (a < 0)
	{
		if (r > 2147483648)
			_error();
	}
	else if (r > 2147483647)
		_error();
}

int	ft_atoi(const char *str)
{
	int				a;
	unsigned long	r;
	int				k;

	k = 0;
	a = 1;
	r = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		a *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		r = r * 10 + *str++ - 48;
		k++;
	}
	return (a * r);
}
