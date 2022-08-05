typedef struct s_link {
	int content;
	struct s_link *next;
}	t_link;

typedef struct s_stack {
	t_list *top;
} t_stack;

t_link	*create_link(int content)
{
	t_link *new;
	new = malloc(sizeof(t_link));
	new->content = content;
	new->next = NULL;
	return (new);
}

int main(void)
{
	t_stack stack;
	stack.top = create_link(32);
	return (0);
}


/*
#include "pswap.h"

t_list	*ft_tab_to_lst(int ac, int *tab)
{
	t_count	c;
	t_list	*list;

	c.i = -1;
	list = NULL;
	if (tab)
		while (++c.i < ac)
			ft_lstadd_back(&list, ft_lstnew(&tab[c.i]));
	return (list);
}

void	ft_show_lstint(t_list *list)
{
	t_list	*tmp;
	t_count	c;

	c.i = -1;
	tmp = list;
	while (tmp)
	{
		ft_printf("(i %d) %d\n", c.i, *(int *)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_memset_lst(t_list *list, void *content)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		tmp->content = content;
		tmp = tmp->next;
	}
}

void	ft_full_free_lst(t_list *list)
{
	t_list	*tmp;
	t_list	*buf;

	tmp = list;
	ft_memset_lst(list, NULL);
	while (tmp)
	{
		buf = tmp->next;
		ft_true_free(tmp);
		tmp = buf;
	}
}

void	ft_push_swap(int ac, t_list *list)
{
	ft_show_lstint(list);
	(void)ac;
	if (list)
		ft_full_free_lst(list);
}

int	main(int ac, char *av[])
{
	int	*trueav;

	av[0] = ft_itoa(ac);
	trueav = ft_pswap_parsing(&ac, av + 1);
	if (!trueav)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_sort_int_tab(trueav, ac);
	if (!ft_check_dup_int(ac, trueav))
	{
		ft_true_free(trueav);
		write(2, "Error\n", 6);
		return (1);
	}
	ft_true_free(trueav);
	ac = ft_atoi(av[0]);
	trueav = ft_pswap_parsing(&ac, av + 1);
	ft_push_swap(ac, ft_tab_to_lst(ac, trueav));
	ft_true_free(trueav);
	ft_true_free(av[0]);
	return (0);
}
*/
