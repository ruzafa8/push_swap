/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:14:00 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/02/19 13:36:12 by aruzafa-         ###   ########.fr       */
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

int	free_all(t_list **instr_lst, t_stacks **stacks, int *parsed_args)
{
	ft_lstclear(instr_lst, ps_del_instr);
	ps_delete_stack(stacks);
	free(parsed_args);
	return (0);
}

static t_list	*get_instr_list(t_stacks *stacks, int *parsed_args, int argc)
{
	t_list	*instr_lst;

	if (stacks->size_a <= 3)
		instr_lst = ps_simple_resolver(stacks);
	else if (stacks->size_a <= 5)
		instr_lst = ps_less_5_resolver(stacks);
	else
	{
		instr_lst = ps_lis_stack(stacks, parsed_args, argc);
		ft_lstadd_back(&instr_lst, ps_greedy_sort(stacks));
	}
	return (instr_lst);
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
		instr_lst = get_instr_list(stacks, parsed_args, argc);
		ps_print_instr(instr_lst);
	}
	return (free_all(&instr_lst, &stacks, parsed_args));
}
