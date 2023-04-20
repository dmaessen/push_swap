/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:46:45 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 10:47:21 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_front_ps(t_stack **lst, t_stack *new)
{
	if (lst)
    {
        if (*lst)
            new->next = *lst;
        *lst = new;
    }
}

void 	pa(t_stack **stacka, t_stack **stackb)
{
	t_stack *temp;

    if (!stackb || !*stackb)
        return ; // what to return? or exit?
	temp = (*stackb);
	(*stackb) = (*stackb)->next;
	temp->next = NULL;
    lstadd_front_ps(stacka, temp);
	write(1, "pa\n", 3);
}

void pb(t_stack **stacka, t_stack **stackb)
{
	t_stack *temp;

    if (!stacka || !*stacka)
        return ; // what to return? or exit?
	temp = (*stacka);
	(*stacka) = (*stacka)->next;
	temp->next = NULL;
    lstadd_front_ps(stackb, temp);
	write(1, "pb\n", 3);
}
