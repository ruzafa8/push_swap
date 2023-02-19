/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:29:00 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/02/19 13:22:17 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_ceil_index(int *arr, int *T, int right, int key)
{
	int	medium;
	int	left;

	left = -1;
	while (right - left > 1)
	{
		medium = left + (right - left) / 2;
		if (arr[T[medium]] >= key)
			right = medium;
		else
			left = medium;
	}
	return (right);
}

int	*reverse(int *x, int len)
{
	int	i;
	int	aux;

	i = 0;
	while (i < len / 2)
	{
		aux = x[i];
		x[i] = x[len - 1 - i];
		x[len - 1 - i] = aux;
		i++;
	}
	return (x);
}

int	*compute_res(int *arr, int *tail_idx, int *prev_idx, int len)
{
	int	i;
	int	pos;
	int	*res;

	res = ft_calloc(len, sizeof(int));
	pos = 0;
	i = tail_idx[len - 1];
	while (i >= 0)
	{
		res[pos++] = arr[i];
		i = prev_idx[i];
	}
	free(tail_idx);
	free(prev_idx);
	return (reverse(res, len));
}

int	*ps_lis(int *arr, int n, int *len, int i)
{
	int	*tail_idx;
	int	*prev_idx;
	int	pos;

	tail_idx = ft_calloc(n, sizeof(int));
	prev_idx = ft_calloc(n, sizeof(int));
	ft_memset((void *) prev_idx, -1, n * sizeof(int));
	while (++i < n)
	{
		if (arr[i] < arr[tail_idx[0]])
			tail_idx[0] = i;
		else if (arr[i] > arr[tail_idx[*len - 1]])
		{
			prev_idx[i] = tail_idx[*len - 1];
			tail_idx[(*len)++] = i;
		}
		else
		{
			pos = get_ceil_index(arr, tail_idx, *len - 1, arr[i]);
			prev_idx[i] = tail_idx[pos - 1];
			tail_idx[pos] = i;
		}
	}
	return (compute_res(arr, tail_idx, prev_idx, *len));
}

t_list	*ps_lis_stack(t_stacks *stack, int *parsed_args, int argc)
{
	int		*lis;
	int		len_lis;
	t_list	*instr;
	int		i;
	int		lis_idx;

	len_lis = 1;
	lis = ps_lis(parsed_args, argc, &len_lis, 0);
	instr = 0;
	i = 0;
	lis_idx = 0;
	while (i < argc)
	{
		if (lis_idx < len_lis && *(int *) stack->a->content == lis[lis_idx])
		{
			ps_add_instr(&instr, ps_rotate(stack, A));
			lis_idx++;
		}
		else
			ps_add_instr(&instr, ps_push(stack, B));
		i++;
	}
	free(lis);
	return (instr);
}
