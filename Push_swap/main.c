/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/03 01:58:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

#include <stdio.h>

char	*ft_pswap_join(char **oldav)
{
	t_count	c;
	char	*full;
	char	*tmp;

	c.i = -1;
	c.a = 0;
	full = NULL;
	while (oldav && oldav[++c.i])
	{
		tmp = full;
		full = ft_strjoin(full, oldav[c.i]);
		if (tmp)
			ft_true_free(tmp);
		tmp = full;
		full = ft_strjoin(full, " ");
		if (tmp)
			ft_true_free(tmp);
		c.a++;
	}
	return (full);
}

int	ft_ps_check_args(int *ac, char *full)
{
	t_count	c;

	c.i = -1;
	*ac = 0;
	while (full[++c.i])
	{
		if (full[c.i] && (full[c.i] == ' ' || ((full[c.i] == '+' || \
		full[c.i] == '-') && (full[c.i + 1] && ft_isdigit(full[c.i + 1])))))
			c.i++;
		else if (full[c.i] && ft_isdigit(full[c.i]))
		{
			*ac += 1;
			while (full[c.i] && ft_isdigit(full[c.i]))
				c.i++;
			if (full[c.i] && full[c.i] != ' ')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	ft_ps_intfinder(char **av)
{
	t_count	c;

	c.i = -1;
	c.j = -1;
	c.x = 0;
	while (av[++c.i])
	{
		while (av[c.i][++c.j] != '\0')
		{
			if (ft_isdigit(av[c.i][c.j]))
				c.x++;
			c.j++;
		}
		if (!c.x)
			return (0);
		c.x = 0;
		c.j = -1;
	}
	return (1);
}

int	*ft_strs_tab(int *ac, char **strs)
{
	t_count	c;
	int		*tab;
	int		x;

	c.i = -1;
	x = 1;
	tab = (int *)malloc(sizeof(int) * (*ac));
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, sizeof(int) * (*ac));
	while (x > 0 && strs && strs[++c.i])
		tab[c.i] = ft_atoi_safe(strs[c.i], &x);
	if (x == 0)
	{
		if (tab)
			ft_true_free(tab);
		return (NULL);
	}
	return (tab);
}

int	*ft_pswap_parsing(int *ac, char **av)
{
	t_count	c;
	char	*full;
	char	**finalcut;
	int		*tab;

	c.i = -1;
	tab = NULL;
	if (*ac < 2 || !av || !ft_ps_intfinder(av))
		return (NULL);
	while (++c.i < (*ac - 1))
	{
		if (av[c.i][0] == '\0')
			return (NULL);
	}
	full = ft_pswap_join(av);
	if (!full || !ft_ps_check_args(ac, full))
		return (NULL);
	finalcut = ft_split(full, ' ');
	tab = ft_strs_tab(ac, finalcut);
	//bug de la gestion des -0 à -9, principal suspect : atoi
	if (full)
		ft_true_free(full);
	if (finalcut)
		ft_full_free((void **)finalcut);
	return (tab);
}

void	ft_show_strs(char **strs)
{
	t_count	c;

	c.i = -1;
	while (strs && strs[++c.i])
		ft_printf("(i%d) : %s\n", c.i, strs[c.i]);
}

void	ft_show_tab(int ac, int *tab)
{
	t_count	c;

	c.i = 0;
	while (tab && c.i < ac)
	{
		ft_printf("(i %d) : %d\n", c.i, tab[c.i]);
		c.i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	size--;
	while (i + 1 <= size)
	{
		if (tab[i] > tab[i + 1])
		{
			n = tab[i];
			tab[i] = tab[i + 1];
			tab [i + 1] = n;
			i = 0;
		}
		else
			i++;
	}
}

int *ft_tabdup(int ac, int *src, int *dest)
{
	t_count c;

	c.i = 0;
	dest = (int *)malloc(sizeof(int) * ac);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, sizeof(int) * ac);
	while (src && c.i < ac)
	{
		dest[c.i] = src[c.i];
		c.i++;
	}
	return (dest);
}

int	ft_find_dup_int(int	ac, int *tab)
{
	t_count	c;

	c.i = 0;
	while (tab && c.i < ac - 1)
	{
		if (tab[c.i] == tab[c.i + 1])
			return (0);
		c.i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int *trueav; // a modifier en **lst
	int *copy;

	copy = NULL;
	trueav = ft_pswap_parsing(&ac, av + 1);
	if (!trueav)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	copy = ft_tabdup(ac, trueav, copy);
	ft_sort_int_tab(copy, ac);
	if (!ft_find_dup_int(ac, copy))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_show_tab(ac, trueav);
	ft_show_tab(ac, copy);
	ft_printf("ac = %d\n", ac);
	if (trueav)
		ft_true_free(trueav);
	if (copy)
		ft_true_free(copy);
	return (0);
}
/*
test({"52"}, true);sequence monoarg
test({"1 2 3"}, true);
test({"1 2 3 4 5"}, true);
test({"5 4 3 2 1"}, true);
test({"52 14 15"}, true);
test({"5 2 3 4 8"}, true);
test({"42 -500 -2845 -21 54784 1541"}, true);
test({"2147483647 -2147483648"}, true);			DONE

test({"5", "4", "3"}, true);sequence multiarg
test({"5", "3", "2", "1"}, true);
test({"5", "1", "0", "2"}, true);				DONE

test({"1 2 3 "}, true); sequence monoarg + espace
test({" 1 2 3"}, true);
test({" 1 2 3 "}, true);
test({" 1   2               3 "}, true);		DONE

test({"-0"}, true); sequence monoarg + zero
test({"05 02"}, true);
test({"052 02"}, true);
test({"05 08 0009 00010 2"}, true);
test({"0002147483647 -002147483648"}, true); limits.h

test({" 5", "8"}, true); sequence multiarg + espace
test({" 5", "3  ", " 2", " 1"}, true);
test({"42", "500", "-2845", "-21", " 54784", "1541"}, true);

test({"4 2 3", "5"}, true); sequence mixte

test({"1 e 2 3 4 5"}, false); intrus
test({"5 4A 3"}, false); intrus
test({"05 5 005"}, false);doublon
test({"-00", "00"}, false);doublon
test({"-0", "0"}, false);doublon
test({"0", "-0"}, false);doublon
*/

//je dois
//
//traiter mes args
//tester les int
//tester les doublons
//produire une liste chainée
//verifier la liste chainée
//
//
//
//
