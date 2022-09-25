/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:34:59 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/24 17:41:57 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	utils_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	utils_heuristic(int rot_a, int rot_b)
{
	int	num_movs;

	num_movs = 0;
	while (rot_a > 0 && rot_b > 0)
	{
		rot_a--;
		rot_b--;
		num_movs++;
	}
	while (rot_a < 0 && rot_b < 0)
	{
		rot_a++;
		rot_b++;
		num_movs++;
	}
	num_movs += utils_abs(rot_a);
	num_movs += utils_abs(rot_b);
	return (num_movs + 1);
}

t_list	*utils_pre_last(t_list *lst)
{
	t_list	*res;

	if (!lst)
		return (0);
	res = 0;
	while (lst->next)
	{
		res = lst;
		lst = lst->next;
	}
	return (res);
}

t_list	*utils_rot_stack(t_stacks *stacks, t_stack stack, int rot)
{
	t_list	*instr;

	instr = 0;
	while (rot > 0)
	{
		ps_add_instr(&instr, ps_rotate(stacks, stack));
		rot--;
	}
	while (rot < 0)
	{
		ps_add_instr(&instr, ps_reverse_rotate(stacks, stack));
		rot++;
	}
	return (instr);
}

void	utils_print_error(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write(2, str, len);
}
