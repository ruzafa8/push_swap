/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:50:28 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/02/18 20:40:46 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_delete_stack(t_stacks **stacks)
{
	if (*stacks)
	{
		ft_lstclear(&((*stacks)->a), (void *) 0);
		ft_lstclear(&((*stacks)->b), (void *) 0);
		free(*stacks);
	}
}
