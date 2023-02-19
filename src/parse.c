/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:12:42 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/02/19 13:25:31 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	count_splitted(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
}

int	*ps_parse(int *argc, char **argv)
{
	char	**split;
	int		*res;

	(*argc)--;
	if (*argc == 0)
		return (0);
	if (!ps_is_number(argv[0]))
	{
		split = ft_split(argv[0], ' ');
		*argc = count_splitted(split);
		res = ps_parse_args(*argc, split);
		free_split(split);
		free(split);
		return (res);
	}
	return (ps_parse_args(*argc, argv));
}
