/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:14:00 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/25 13:31:24 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static int	is_ordered(t_stacks *stacks)
{
	t_list	*lst;

	lst = stacks->a;
	while (lst && lst->next)
	{
		if (*(int *) lst->content > *(int *) lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	free_all(t_stacks **stacks, t_list **instr_lst)
{
	if (*instr_lst)
	{
		ft_lstclear(instr_lst, free);
		free(*instr_lst);
	}
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
	if (ch_read_instr(&instr_lst))
	{
		ch_process_instr(stacks, instr_lst);
		if (is_ordered(stacks))
			ft_printf("OK");
		else
			ft_printf("KO");
	}
	else
		utils_print_error("Error\n");
	return (free_all(&stacks, &instr_lst));
}
