/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:26:16 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/24 13:50:52 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

typedef enum e_token
{
	SA_TOK,
	SB_TOK,
	SS_TOK,
	PA_TOK,
	PB_TOK,
	RA_TOK,
	RB_TOK,
	RR_TOK,
	RRA_TOK,
	RRB_TOK,
	RRR_TOK,
	ERROR_TOK
}	t_token;

int		ch_read_instr(t_list **instr);
void	ch_process_instr(t_stacks *stacks, t_list *tokens);

#endif
