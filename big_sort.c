/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:55:34 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 13:38:02 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// NEW OPTION
void big_sort(t_stack **stacka, t_stack **stackb)
{
    int index_top;
	int index_bottom;
	int x;
	int size;
	int buck;

	index_stack(stacka);
	size = stack_size(*stacka);
	buck = (size / buckets(*stacka));
	x = 0;
	while (*stacka)
	{
		// if (stack_size(*stacka) <= 100)
		// 	x = scan_b100(*stackb);
		// else
		// 	x = scan_b500(*stackb);
		if (stack_size(*stackb) % buck == 0)
			x = x + buck;
		index_top = search_top(*stacka, x);
		index_bottom = search_bottom(*stacka, x);
		move_to_b(stacka, stackb, index_top, index_bottom);
	}

	// ft_print_stack(*stackb); // to rm
	
	// size = stack_size(*stackb);
	// x = 0;
	// while (*stackb) // THAN PUSH BACK TO A -- with biggest first
	// {
	// 	if ((*stackb)->indexx == size - x)
	// 	{
	// 		pa(stacka, stackb);
	// 		x++;
	// 	}
	// 	else // or calculate again rb or rrb more efficient ??
	// 		rb(stackb);
	// }
	// ft_print_stack(*stacka); // to rm

	
	while (*stackb)
	{
		x = locate_biggest(*stackb);
		if (x == 0)
			pa(stacka, stackb);
		else if (x < (stack_size(*stackb) / 2)) // if x located in top half
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
	// printf("A\n");
	// ft_print_stack(*stacka); // to rm
// 	if (isordered(*stacka) == 0)
//         printf("IN ORDER\n");
}

int locate_biggest(t_stack *stackb)
{
	int i;
	int size;

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

int buckets(t_stack *stacka)
{
	int i;
	int sq;
	int size;
	
	size = stack_size(stacka);
	i = 1;
	while (1)
	{
		sq = (i * i);
		if (sq > size)
			break;
		i++;
	}
	return (i / 2);
}

int scan_b100(t_stack *stackb)
{
	if (stack_size(stackb) < 20)
		return (20);
	else if (stack_size(stackb) < 40)
		return (40);
	else if (stack_size(stackb) < 60)
		return (60);
	else if (stack_size(stackb) < 80)
		return (80);
	else
		return (100);
}

int scan_b500(t_stack *stackb)
{
	if (stack_size(stackb) < 46)
		return (46);
	else if (stack_size(stackb) < 91)
		return (91);
	else if (stack_size(stackb) < 136)
		return (136);
	else if (stack_size(stackb) < 181)
		return (181);
	else if (stack_size(stackb) < 226)
		return (226);
	else if (stack_size(stackb) < 271)
		return (271);
	else if (stack_size(stackb) < 316)
		return (316);
	else if (stack_size(stackb) < 361)
		return (361);
	else if (stack_size(stackb) < 406)
		return (406);
	else if (stack_size(stackb) < 451)
		return (451);
	else
		return (stack_size(stackb)); // in case bigger
}

int search_top(t_stack *stacka, int x)
{
	int size;
	int i;

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
	int i;

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
	return (current); // or something else
}

int search_bottom(t_stack *stacka, int x)
{
	int size;
	t_stack *last;

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

void move_to_b(t_stack **stacka, t_stack **stackb, int top, int bottom)
{
	int i;

	if ((stack_size(*stacka) - bottom) < top)
	{
		if ((stack_size(*stacka) - bottom) == 0)
			rra(stacka);
		else
		{
			i = 1;
			while (i <= (stack_size(*stacka) - bottom))
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
		{
			i = 0;
			while (i < top)
			{
				ra(stacka);
				i++;
			}
		}
	}
	pb(stacka, stackb);
}



/*
APPROACH:
    - devide the stack in 5 for 100 and 11 for 500
    - find the last node of list/stack

    - find median 
    

https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/


tried ./push_swap 2 7 3 5 6 1 9
and index is broke wtf

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
insertion algo

https://github.com/o-reo/push_swap_visualizer 
./push_swap_visualizer/build/bin/visualizer


FIX LITTE_FOUR AND LITTLE_FIVE

*/