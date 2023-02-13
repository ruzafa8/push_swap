/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:21:24 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/24 16:17:22 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	where_shoud_be_at_a(t_list *lst, int size, int elem)
{
	int	i;
	int	content;
	int	next_content;

	i = 0;
	while (lst != 0 && lst->next != 0)
	{
		content = *(int *) lst->content;
		next_content = *(int *) lst->next->content;
		if ((next_content < content && elem > content)
			|| (next_content < content && elem < next_content)
			|| (content < elem && next_content > elem))
		{
			if (i < size / 2)
				return (i + 1);
			return ((size - i - 1) * -1);
		}
		lst = lst->next;
		i++;
	}
	return (0);
}

static void	min_rotation(t_stacks *stacks, int *rot_a, int *rot_b)
{
	size_t	i;
	int		elem;
	int		pos_a;
	t_list	*b;
	int		pos_b;

	b = stacks->b;
	i = 0;
	while (i < stacks->size_b)
	{
		elem = *(int *)b->content;
		pos_a = where_shoud_be_at_a(stacks->a, stacks->size_a, elem);
		if (stacks->size_b < 2 || i < stacks->size_b / 2)
			pos_b = i;
		else
			pos_b = (stacks->size_b - i) * -1;
		if (i == 0 || utils_heuristic(pos_a, pos_b)
			< utils_heuristic(*rot_a, *rot_b))
		{
			*rot_a = pos_a;
			*rot_b = pos_b;
		}
		b = b->next;
		i++;
	}
}

static t_list	*apply_rot(t_stacks *stacks, int rot_a, int rot_b)
{
	t_list	*instr;

	instr = 0;
	while (rot_a > 0 && rot_b > 0)
	{
		ps_add_instr(&instr, ps_rotate(stacks, BOTH));
		rot_a--;
		rot_b--;
	}
	while (rot_a < 0 && rot_b < 0)
	{
		ps_add_instr(&instr, ps_reverse_rotate(stacks, BOTH));
		rot_a++;
		rot_b++;
	}
	ft_lstadd_back(&instr, utils_rot_stack(stacks, A, rot_a));
	ft_lstadd_back(&instr, utils_rot_stack(stacks, B, rot_b));
	ps_add_instr(&instr, ps_push(stacks, A));
	return (instr);
}

static t_list	*order(t_stacks *stacks)
{
	t_list	*a;
	t_list	*instr;
	size_t	i;

	i = 1;
	instr = 0;
	a = stacks->a;
	while (a != 0 && a->next != 0
		&& *(int *)a->content < *(int *)a->next->content)
	{
		i++;
		a = a->next;
	}
	if (a == 0 || a->next == 0)
		return (0);
	if (i < stacks->size_a / 2)
		while (i--)
			ps_add_instr(&instr, ps_rotate(stacks, A));
	else
	{
		i = stacks->size_a - i;
		while (i--)
			ps_add_instr(&instr, ps_reverse_rotate(stacks, A));
	}
	return (instr);
}

t_list	*ps_greedy_sort(t_stacks *stacks)
{
	int		rot_a;
	int		rot_b;
	t_list	*instr;

	instr = 0;
	while (stacks->size_b)
	{
		min_rotation(stacks, &rot_a, &rot_b);
		ft_lstadd_back(&instr, apply_rot(stacks, rot_a, rot_b));
	}
	ft_lstadd_back(&instr, order(stacks));
	return (instr);
}
