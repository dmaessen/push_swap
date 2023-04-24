/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:12:12 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 17:13:00 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_two(t_stack **stacka)
{
	if ((*stacka)->data > (*stacka)->next->data)
		sa(stacka);
}

void	little_three(t_stack **stacka)
{
	if (((*stacka)->data > (*stacka)->next->data)
		&& ((*stacka)->next->next->data > (*stacka)->data))
		sa(stacka);
	else if (((*stacka)->data > (*stacka)->next->next->data)
		&& ((*stacka)->next->next->data > (*stacka)->next->data))
		ra(stacka);
	else if (((*stacka)->data < (*stacka)->next->data)
		&& ((*stacka)->next->next->data < (*stacka)->data))
		rra(stacka);
	else if (((*stacka)->data > (*stacka)->next->data)
		&& ((*stacka)->next->data > (*stacka)->next->next->data))
	{
		sa(stacka);
		rra(stacka);
	}
	else if (((*stacka)->data < (*stacka)->next->data)
		&& ((*stacka)->next->data > (*stacka)->next->next->data))
	{
		sa(stacka);
		ra(stacka);
	}
}

void	find_smallest(t_stack **stacka)
{
	t_stack	*temp;
	t_stack	*last;
	int		min;
	int		i;

	min = INT_MAX;
	i = 0;
	temp = (*stacka);
	while (temp)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
		i++;
	}
	last = lstlast_ps(*stacka);
	if (last->data == min)
		rra(stacka);
	else
	{
		while ((*stacka)->data != min)
			ra(stacka);
	}
}

void	little_four(t_stack **stacka, t_stack **stackb)
{
	find_smallest(stacka);
	pb(stacka, stackb);
	little_three(stacka);
	pa(stacka, stackb);
}

void	little_five(t_stack **stacka, t_stack **stackb)
{
	find_smallest(stacka);
	pb(stacka, stackb);
	find_smallest(stacka);
	pb(stacka, stackb);
	little_three(stacka);
	pa(stacka, stackb);
	pa(stacka, stackb);
}
