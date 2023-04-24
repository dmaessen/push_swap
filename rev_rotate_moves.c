/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:13:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/21 11:08:57 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*lst_previouslast(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next->next != NULL)
		current = current->next;
	return (current);
}

void	rra(t_stack **stacka)
{
	t_stack	*first;
	t_stack	*last;

	first = lstlast_ps(*stacka);
	last = lst_previouslast(*stacka);
	first->next = (*stacka);
	(*stacka) = first;
	last->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stackb)
{
	t_stack	*first;
	t_stack	*last;

	first = lstlast_ps(*stackb);
	last = lst_previouslast(*stackb);
	first->next = (*stackb);
	(*stackb) = first;
	last->next = NULL;
	write(1, "rrb\n", 4);
}
