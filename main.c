/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:14:00 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/02/18 20:49:12 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ordered(int *n, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (n[i] > n[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	free_all(t_list **instr_lst, t_stacks **stacks)
{
	ft_lstclear(instr_lst, ps_del_instr);
	ps_delete_stack(stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	int			*parsed_args;
	t_stacks	*stacks;
	t_list		*instr_lst;

	parsed_args = ps_parse(&argc, argv + 1);
	stacks = 0;
	instr_lst = 0;
	if (argc == 0)
		return (0);
	if (!parsed_args)
	{
		utils_print_error("Error\n");
		return (0);
	}
	if (!ordered(parsed_args, argc))
	{
		stacks = ps_create_stacks(argc, parsed_args);
		if (stacks->size_a <= 3)
			instr_lst = ps_simple_resolver(stacks);
		else if (stacks->size_a <= 5)
			instr_lst = ps_less_5_resolver(stacks);
		else
		{
			instr_lst = ps_lis_stack(stacks, parsed_args, argc);
			ft_lstadd_back(&instr_lst, ps_greedy_sort(stacks));
		}
		ps_print_instr(instr_lst);
	}
	free(parsed_args);
	return free_all(&instr_lst, &stacks);
}
