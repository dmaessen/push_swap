/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:25:16 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/12 14:42:58 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stacka)
{
	int temp;

	// check if stack is NULL?? or 1data ??
	temp = (*stacka)->data;
	(*stacka)->data = (*stacka)->next->data;
	(*stacka)->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stackb)
{
    int temp;

	// check if stack is NULL?? or 1data ??
	temp = (*stackb)->data;
	(*stackb)->data = (*stackb)->next->data;
	(*stackb)->next->data = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	int temp;
	int tempb;

	// check if stack is NULL?? or 1data ??
	temp = (*stacka)->data;
	(*stacka)->data = (*stacka)->next->data;
	(*stacka)->next->data = temp;
	tempb = (*stackb)->data;
	(*stackb)->data = (*stackb)->next->data;
	(*stackb)->next->data = tempb;
	write(1, "ss\n", 3);
}