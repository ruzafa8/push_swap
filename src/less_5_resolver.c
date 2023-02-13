/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_5_resolver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:29:27 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/19 17:47:14 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ps_less_5_resolver(t_stacks *stacks)
{
	t_list	*instr;

	instr = 0;
	while (stacks->size_a > 3)
		ps_add_instr(&instr, ps_push(stacks, B));
	ft_lstadd_back(&instr, ps_simple_resolver(stacks));
	ft_lstadd_back(&instr, ps_greedy_sort(stacks));
	return (instr);
}
