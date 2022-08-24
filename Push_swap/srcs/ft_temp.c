/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_temp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:12:12 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/23 21:38:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

typedef struct s_control {
	int	ac;
	int	min;
	int	max;
	int	firstthird;
	int	lastthird;
	int	pop_a;
	int	pop_ea;
	int	pop_b;
	int	pop_eb;
	int	lock;
	int	total;
}	t_control;

t_control	ft_fill_controlval(int ac)
{
	t_control	values;

	values.ac = ac;
	values.min = 1;
	values.max = ac;
	values.firstthird = (ac + 1) / 3;
	values.lastthird = (ac + 1) * 2 / 3;
	values.pop_a = ac;
	values.lock = 0;
	values.pop_ea = 0;
	values.pop_b = 0;
	values.pop_eb = 0;
	values.total = 0;
	return (values);
}

void	ft_show_values(t_control values)
{
	printf("ac %d\t", values.ac);
	printf("min[%d ", values.min);
	printf("to %d]max\n", values.max);
	printf("1/3 at %d\t", values.firstthird);
	printf("2/3 at %d\n\n", values.lastthird);
	printf("pop  a %d\t", values.pop_a);
	printf("pop  b %d\n", values.pop_b);
	printf("lock a %d\t", values.lock);
	printf("total  %d\n", values.total);
	printf("pop ea %d\t", values.pop_ea);
	printf("pop eb %d\n\n", values.pop_eb);
}

void	ft_test(t_control *val)
{
	t_control	stock;

	printf("initiale 1\n");
	ft_show_values(*val);
	stock = *val;
	printf("stockée 1\n");
	ft_show_values(stock);
	val->max = 50;
	printf("initiale 2\n");
	ft_show_values(*val);
	printf("stockée 2\n");
	ft_show_values(stock);
	*val = stock;
	printf("initiale 3\n");
	ft_show_values(*val);
	printf("stockée 3\n");
	ft_show_values(stock);
}

int	main(void)
{
	t_control	val;

	val = ft_fill_controlval(10);
	ft_test(&val);
	return (0);
}
*/
