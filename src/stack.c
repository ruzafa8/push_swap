/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:19:24 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/24 17:55:30 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_instr	ps_swap(t_stacks *stacks, t_stack stack)
{
	int	aux;

	if ((stack == A || stack == BOTH) && stacks->size_a >= 2)
	{
		aux = *(int *)stacks->a->content;
		*(int *) stacks->a->content = *(int *)stacks->a->next->content;
		*(int *) stacks->a->next->content = aux;
	}
	if ((stack == B || stack == BOTH) && stacks->size_b >= 2)
	{
		aux = *(int *)stacks->b->content;
		*(int *) stacks->b->content = *(int *)stacks->b->next->content;
		*(int *) stacks->b->next->content = aux;
	}
	if (stack == A)
		return (SA);
	else if (stack == B)
		return (SB);
	return (SS);
}

t_instr	ps_push(t_stacks *stacks, t_stack stack)
{
	t_list	*node;

	if (stack == A && stacks->size_b > 0)
	{
		node = stacks->b;
		stacks->b = stacks->b->next;
		node->next = stacks->a;
		stacks->a = node;
		stacks->size_b--;
		stacks->size_a++;
	}
	else if (stack == B && stacks->size_a > 0)
	{
		node = stacks->a;
		stacks->a = stacks->a->next;
		node->next = stacks->b;
		stacks->b = node;
		stacks->size_b++;
		stacks->size_a--;
	}
	if (stack == A)
		return (PA);
	return (PB);
}

t_instr	ps_rotate(t_stacks *stacks, t_stack stack)
{
	t_list	*lst;

	if ((stack == A || stack == BOTH) && stacks->size_a >= 2)
	{
		lst = ft_lstlast(stacks->a);
		lst->next = stacks->a;
		stacks->a = stacks->a->next;
		lst->next->next = 0;
	}
	if ((stack == B || stack == BOTH) && stacks->size_b >= 2)
	{
		lst = ft_lstlast(stacks->b);
		lst->next = stacks->b;
		stacks->b = stacks->b->next;
		lst->next->next = 0;
	}
	if (stack == A)
		return (RA);
	else if (stack == B)
		return (RB);
	return (RR);
}

t_instr	ps_reverse_rotate(t_stacks *stacks, t_stack stack)
{
	t_list	*pre;
	t_list	*lst;

	if ((stack == A || stack == BOTH) && stacks->size_a >= 2)
	{
		pre = utils_pre_last(stacks->a);
		lst = pre->next;
		lst->next = stacks->a;
		stacks->a = lst;
		pre->next = 0;
	}
	if ((stack == B || stack == BOTH) && stacks->size_b >= 2)
	{
		pre = utils_pre_last(stacks->b);
		lst = pre->next;
		lst->next = stacks->b;
		stacks->b = lst;
		pre->next = 0;
	}
	if (stack == A)
		return (RRA);
	else if (stack == B)
		return (RRB);
	return (RRR);
}

t_stacks	*ps_create_stacks(int argc, int *argv)
{
	int			i;
	t_list		*node;
	t_stacks	*stacks;

	i = argc - 1;
	stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (0);
	stacks->size_a = argc;
	while (i >= 0)
	{
		node = ft_lstnew(argv + i);
		ft_lstadd_front(&(stacks->a), node);
		i--;
	}
	return (stacks);
}
