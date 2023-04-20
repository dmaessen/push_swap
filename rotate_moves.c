/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:52:12 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 10:46:31 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lstadd_back_r(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = lstlast_ps(*lst);
		current->next = new;
	}
}

void ra(t_stack **stacka) 
{
    t_stack *last;
    t_stack *temp;
    
    // check if stack is NULL?? or 1data ??
    last = (*stacka);
    temp = (*stacka)->next;
    (*stacka) = temp;
    lstadd_back_r(stacka, last);
    last->next = NULL;
    write(1, "ra\n", 3);
}

void rb(t_stack **stackb)
{
    t_stack *lastb;
    t_stack *temp;

    // check if stack is NULL?? or 1data ??
    lastb = (*stackb);
    temp = (*stackb)->next;
    (*stackb) = temp;
    lstadd_back_r(stackb, lastb);
    lastb->next = NULL;
    write(1, "rb\n", 3);
}

void rr(t_stack **stacka, t_stack **stackb)
{
    t_stack *last;
    t_stack *lastb;
    t_stack *temp;
    t_stack *tempb;

    // check if stack is NULL?? or 1data ??
    last = (*stacka);
    temp = (*stacka)->next;
    (*stacka) = temp;
    lstadd_back_r(stacka, last);
    last->next = NULL;
    lastb = (*stackb);
    tempb = (*stackb)->next;
    (*stackb) = tempb;
    lstadd_back_r(stackb, lastb);
    lastb->next = NULL;
    write(1, "rr\n", 3);
}
