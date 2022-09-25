/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_resolver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:20:21 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/18 16:18:43 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*resolver_3var(t_stacks *stack)
{
	t_list	*lst;
	int		first;
	int		second;
	int		third;
	t_instr	instr;

	first = *(int *) stack->a->content;
	second = *(int *) stack->a->next->content;
	third = *(int *) stack->a->next->next->content;
	lst = 0;
	if (first < second && second < third)
		return (lst);
	if (first < third && third < second)
		instr = ps_reverse_rotate(stack, A);
	else if (second < first && first < third)
		instr = ps_swap(stack, A);
	else if (second < third && third < first)
		instr = ps_rotate(stack, A);
	else if (third < first && first < second)
		instr = ps_reverse_rotate(stack, A);
	else
		instr = ps_swap(stack, A);
	ps_add_instr(&lst, instr);
	ft_lstadd_back(&lst, resolver_3var(stack));
	return (lst);
}

t_list	*ps_simple_resolver(t_stacks *stack)
{
	t_list	*res;
	int		first;
	int		second;

	res = 0;
	if (stack->size_a == 1)
		return (0);
	first = *(int *) stack->a->content;
	second = *(int *) stack->a->next->content;
	if (stack->size_a == 2 && first > second)
		ps_add_instr(&res, ps_rotate(stack, A));
	else if (stack->size_a == 3)
		res = resolver_3var(stack);
	return (res);
}

t_list	*ps_move_top_partition(t_stacks *stack, int partition_len)
{
	t_list	*res;

	res = 0;
	if (partition_len == 0)
		return (0);
	if (partition_len == 1)
		ps_add_instr(&res, ps_push(stack, A));
	if (partition_len == 2)
	{
		if (*(int *)stack->b->content < *(int *) stack->b->next->content)
			ps_add_instr(&res, ps_swap(stack, B));
		ps_add_instr(&res, ps_push(stack, A));
		ps_add_instr(&res, ps_push(stack, A));
	}
	return (res);
}
