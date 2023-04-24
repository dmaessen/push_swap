/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:55:34 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/21 13:41:26 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **stacka, t_stack **stackb)
{
	int	index_top;
	int	index_bottom;
	int	x;
	int	buck;

	index_stack(stacka);
	buck = (stack_size(*stacka) / buckets(*stacka));
	x = 0;
	while (*stacka)
	{
		if (stack_size(*stackb) % buck == 0)
			x = x + buck;
		index_top = search_top(*stacka, x);
		index_bottom = search_bottom(*stacka, x);
		move_to_b(stacka, stackb, index_top, index_bottom);
	}
	push_back(stacka, stackb, x);
}

void	push_back(t_stack **stacka, t_stack **stackb, int x)
{
	while (*stackb)
	{
		x = locate_biggest(*stackb);
		if (x == 0)
			pa(stacka, stackb);
		else if (x < (stack_size(*stackb) / 2))
		{
			while (x > 0)
			{
				rb(stackb);
				x--;
			}
			pa(stacka, stackb);
		}
		else
		{
			while (x < stack_size(*stackb))
			{
				rrb(stackb);
				x++;
			}
			pa(stacka, stackb);
		}
	}
}

void	move_to_b(t_stack **stacka, t_stack **stackb, int top, int b)
{
	int	i;

	if ((stack_size(*stacka) - b) < top)
	{
		if ((stack_size(*stacka) - b) == 0)
			rra(stacka);
		else
		{
			i = 1;
			while (i <= (stack_size(*stacka) - b))
			{
				rra(stacka);
				i++;
			}
		}
	}
	else
	{
		if (top == 1)
			ra(stacka);
		else
			move_to_b2(stacka, top);
	}
	pb(stacka, stackb);
}

void	move_to_b2(t_stack **stacka, int top)
{
	int	i;

	i = 0;
	while (i < top)
	{
		ra(stacka);
		i++;
	}
}
