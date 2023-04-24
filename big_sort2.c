/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:33:38 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 17:34:54 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate_biggest(t_stack *stackb)
{
	int	i;
	int	size;

	size = stack_size(stackb);
	i = 0;
	while (stackb)
	{
		if (stackb->indexx == size)
			return (i);
		stackb = stackb->next;
		i++;
	}
	return (0);
}

int	buckets(t_stack *stacka)
{
	int	i;
	int	sq;
	int	size;

	size = stack_size(stacka);
	i = 1;
	while (1)
	{
		sq = (i * i);
		if (sq > size)
			break ;
		i++;
	}
	return (i / 2);
}

int	search_top(t_stack *stacka, int x)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(stacka);
	while (i < size)
	{
		if (stacka->indexx <= x)
			return (i);
		if (stacka->next)
			stacka = stacka->next;
		i++;
	}
	exit(EXIT_FAILURE);
}

t_stack	*lst_position(t_stack *lst, int iter)
{
	t_stack	*current;
	int		i;

	current = lst;
	if (current == NULL)
		return (NULL);
	i = 0;
	while (1)
	{
		if (i == iter)
			return (current);
		if (current->next)
			current = current->next;
		i++;
	}
	return (current);
}

int	search_bottom(t_stack *stacka, int x)
{
	int		size;
	t_stack	*last;

	size = stack_size(stacka);
	while (size >= 0)
	{
		last = lst_position(stacka, size);
		if (last->indexx <= x)
			return (size);
		size--;
	}
	exit(EXIT_FAILURE);
}
