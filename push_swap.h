/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:37:49 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/24 17:44:47 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft.h"

typedef struct s_stacks
{
	t_list	*a;
	size_t	size_a;
	t_list	*b;
	size_t	size_b;
}	t_stacks;

typedef enum e_stack
{
	A,
	B,
	BOTH
}	t_stack;

typedef enum e_instr
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_instr;

int			*ps_parse_args(int argc, char **argv);
int			ps_is_number(char *str);
int			*ps_parse(int *argc, char **argv);

t_instr		ps_swap(t_stacks *stacks, t_stack stack);
t_instr		ps_push(t_stacks *stacks, t_stack stack);
t_instr		ps_rotate(t_stacks *stacks, t_stack stack);
t_instr		ps_reverse_rotate(t_stacks *stacks, t_stack stack);
t_stacks	*ps_create_stacks(int argc, int *argv);
void		ps_delete_stack(t_stacks **stack);

t_list		*utils_pre_last(t_list *lst);
int			utils_heuristic(int rot_a, int rot_b);
t_list		*utils_rot_stack(t_stacks *stacks, t_stack stack, int rot);
void		utils_print_error(char *str);

t_list		*ps_simple_resolver(t_stacks *stack);
t_list		*ps_move_top_partition(t_stacks *stack, int partition_len);

void		ps_add_instr(t_list **lst, t_instr instr);
void		ps_print_instr(t_list *list);
void		ps_add_part(t_list **lst, int part_size);
void		ps_del_instr(t_list **lst);

int			*ps_lis(int *arr, int size, int *len, int i);
t_list		*ps_lis_stack(t_stacks *stack, int *parsed_args, int argc);

t_list		*ps_greedy_sort(t_stacks *stacks);

t_list		*ps_less_5_resolver(t_stacks *stacks);

void		print_stack(t_stacks *s);
#endif
