/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:27:36 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/19 18:16:35 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_is_number(char *s)
{
	if (*s && *s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	ps_present(int value, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static int	ps_overflow(int val, char *str)
{
	return ((val == -1 && *str != '-') || (val == 0 && *str == '-'));
}

int	*ps_parse_args(int argc, char **argv)
{
	int	i;
	int	*res;
	int	num;

	i = 0;
	res = ft_calloc(argc, sizeof(int));
	if (!res)
		return (0);
	while (i < argc)
	{
		if (!ps_is_number(argv[i]))
		{
			free(res);
			return (0);
		}
		num = ft_atoi(argv[i]);
		if (ps_present(num, res, i) || ps_overflow(num, argv[i]))
		{
			free(res);
			return (0);
		}
		res[i] = num;
		i++;
	}
	return (res);
}
