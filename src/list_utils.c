/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:05:48 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/09/18 12:08:20 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	list_del_first(t_list **lst)
{
	t_list	*first;

	first = *lst;
	*lst = (*lst)->next;
	ft_lstdelone(first, free);
}
