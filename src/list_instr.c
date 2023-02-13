/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:20:11 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/18 17:46:59 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_add_part(t_list **lst, int partition_val)
{
	int		*cont;

	if (partition_val)
	{
		cont = ft_calloc(1, sizeof(int));
		*cont = partition_val;
		ft_lstadd_front(lst, ft_lstnew((void *) cont));
	}
}

void	ps_add_instr(t_list **lst, t_instr instr)
{
	t_list	*new;
	t_instr	*i;

	i = ft_calloc(1, sizeof(t_instr));
	*i = instr;
	new = ft_lstnew((void *) i);
	ft_lstadd_back(lst, new);
}

static void	print_instr(void *con)
{
	t_instr	i;

	i = *(t_instr *) con;
	if (i == SA)
		ft_printf("sa\n");
	else if (i == SB)
		ft_printf("sb\n");
	else if (i == SS)
		ft_printf("ss\n");
	else if (i == PA)
		ft_printf("pa\n");
	else if (i == PB)
		ft_printf("pb\n");
	else if (i == RA)
		ft_printf("ra\n");
	else if (i == RB)
		ft_printf("rb\n");
	else if (i == RR)
		ft_printf("rr\n");
	else if (i == RRA)
		ft_printf("rra\n");
	else if (i == RRB)
		ft_printf("rrb\n");
	else if (i == RRR)
		ft_printf("rrr\n");
}

void	ps_del_instr(t_list **lst)
{
	t_list	*node;

	if (!*lst)
		return ;
	node = *lst;
	*lst = (*lst)->next;
	free(node->content);
	free(node);
}

void	ps_print_instr(t_list *list)
{
	ft_lstiter(list, print_instr);
}
