/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:39:10 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 17:10:34 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_init(t_stack *stacka)
{
	while (stacka != NULL)
	{
		stacka->indexx = -1;
		stacka = stacka->next;
	}
}

int	index_min(t_stack *stacka, int i)
{
	int	min;

	min = INT_MAX;
	while (stacka != NULL)
	{
		if ((i == 1) && (min > stacka->data))
			min = stacka->data;
		if ((stacka->indexx == -1) && (min > stacka->data))
			min = stacka->data;
		stacka = stacka->next;
	}
	return (min);
}

void	index_stack(t_stack **stacka)
{
	t_stack	*temp;
	int		i;
	int		min;
	int		size;

	temp = *stacka;
	index_init(*stacka);
	i = 1;
	size = stack_size(*stacka);
	while (i <= size)
	{
		min = index_min(*stacka, i);
		while (*stacka != NULL)
		{
			if ((*stacka)->data == min)
			{
				(*stacka)->indexx = i;
				i++;
			}
			*stacka = (*stacka)->next;
		}
		*stacka = temp;
	}
}
