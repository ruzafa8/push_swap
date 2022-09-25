/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:14:00 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/24 18:00:40 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	free_all(t_list **instr_lst, t_stacks **stacks)
{
	ps_del_instr(instr_lst);
	ps_delete_stack(stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	int			*parsed_args;
	t_stacks	*stacks;
	t_list		*instr_lst;

	argc--;
	parsed_args = ps_parse(&argc, argv + 1);
	if (argc == 0)
		return (0);
	if (!parsed_args)
	{
		utils_print_error("Error\n");
		return (0);
	}
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
	return (free_all(&instr_lst, &stacks));
}
