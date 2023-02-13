/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:23:39 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/25 13:30:52 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static t_token	scan(char *buf)
{
	if (ft_strncmp(buf, "sa\n", 3) == 0)
		return (SA_TOK);
	else if (ft_strncmp(buf, "sb\n", 3) == 0)
		return (SB_TOK);
	else if (ft_strncmp(buf, "ss\n", 3) == 0)
		return (SS_TOK);
	else if (ft_strncmp(buf, "pa\n", 3) == 0)
		return (PA_TOK);
	else if (ft_strncmp(buf, "pb\n", 3) == 0)
		return (PB_TOK);
	else if (ft_strncmp(buf, "ra\n", 3) == 0)
		return (RA_TOK);
	else if (ft_strncmp(buf, "rb\n", 3) == 0)
		return (RB_TOK);
	else if (ft_strncmp(buf, "rrr\n", 4) == 0)
		return (RRR_TOK);
	else if (ft_strncmp(buf, "rra\n", 4) == 0)
		return (RRA_TOK);
	else if (ft_strncmp(buf, "rrb\n", 4) == 0)
		return (RRB_TOK);
	else if (ft_strncmp(buf, "rr\n", 3) == 0)
		return (RR_TOK);
	return (ERROR_TOK);
}

static void	apply_instr(t_stacks *stacks, t_token token)
{
	if (token == SA_TOK)
		ps_swap(stacks, A);
	else if (token == SB_TOK)
		ps_swap(stacks, B);
	else if (token == SS_TOK)
		ps_swap(stacks, BOTH);
	else if (token == PA_TOK)
		ps_push(stacks, A);
	else if (token == PB_TOK)
		ps_push(stacks, B);
	else if (token == RA_TOK)
		ps_rotate(stacks, A);
	else if (token == RB_TOK)
		ps_rotate(stacks, B);
	else if (token == RR_TOK)
		ps_rotate(stacks, BOTH);
	else if (token == RRA_TOK)
		ps_reverse_rotate(stacks, A);
	else if (token == RRB_TOK)
		ps_reverse_rotate(stacks, B);
	else if (token == RRR_TOK)
		ps_reverse_rotate(stacks, BOTH);
}

static void	insert_node(t_list **lst, t_token tok)
{
	t_list	*new_node;
	t_token	*content;

	content = ft_calloc(1, sizeof(t_token));
	*content = tok;
	new_node = ft_lstnew((void *) content);
	ft_lstadd_back(lst, new_node);
}

void	ch_process_instr(t_stacks *stacks, t_list *tokens)
{
	while (tokens)
	{
		apply_instr(stacks, *((t_token *)tokens->content));
		tokens = tokens->next;
	}
}

int	ch_read_instr(t_list **instr)
{
	char	*buf;
	t_token	read;

	while (42)
	{
		buf = ft_get_next_line(0);
		if (!buf)
			return (1);
		read = scan(buf);
		free(buf);
		if (read == ERROR_TOK)
			return (ft_strncmp(buf, "\0", 1) == 0);
		insert_node(instr, read);
	}
	return (1);
}
