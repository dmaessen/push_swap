/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:12:12 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 11:32:22 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void little_two(t_stack **stacka)
{
	if ((*stacka)->data > (*stacka)->next->data)
		sa(stacka);
}

void little_three(t_stack **stacka)
{
	if (((*stacka)->data > (*stacka)->next->data) &&
		((*stacka)->next->next->data > (*stacka)->data))
		sa(stacka);
	else if (((*stacka)->data > (*stacka)->next->next->data) &&
		((*stacka)->next->next->data > (*stacka)->next->data))
		ra(stacka);
	else if (((*stacka)->data < (*stacka)->next->data) &&
		((*stacka)->next->next->data < (*stacka)->data))
		rra(stacka);
	else if (((*stacka)->data > (*stacka)->next->data) &&
		((*stacka)->next->data > (*stacka)->next->next->data))
	{
		sa(stacka);
		rra(stacka);
	}
	else if (((*stacka)->data < (*stacka)->next->data) &&
		((*stacka)->next->data > (*stacka)->next->next->data))
	{
		sa(stacka);
		ra(stacka);
	}
}

void little_four(t_stack **stacka, t_stack **stackb) // LOOK AGAIN
{
	pb(stacka, stackb);
	little_three(stacka);
	pa(stacka, stackb);
	while (isordered(*stacka) != 0)
	{
		if (((*stacka)->data > (*stacka)->next->data))
			sa(stacka);
		else
			rra(stacka);
	}
	
}

void little_five(t_stack **stacka, t_stack **stackb) // fix this, doesn't work with 42153
{
	// t_stack *last;
	
	pb(stacka, stackb);
	pb(stacka, stackb);
	little_three(stacka);
	pa(stacka, stackb);
	pa(stacka, stackb);
	while (isordered(*stacka) != 0)
	{
		// last = lstlast_ps(*stacka);
		if (((*stacka)->data > (*stacka)->next->data))
			sa(stacka);
		else
			rra(stacka);
	}
	printf("EXEC -- LITTLE 5\n");
	printf("data1 %i // data2 %i // data3 %i // data4 %i // data5 %i \n", (*stacka)->data, (*stacka)->next->data, (*stacka)->next->next->data, (*stacka)->next->next->next->data, (*stacka)->next->next->next->next->data);
}
