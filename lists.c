/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:49:26 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/17 16:24:56 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast_ps(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	lstadd_back_ps(t_stack **lst, long long int res)
{
	t_stack	*current;
	t_stack *new;

	new = lstnew_ps(res); // check if NULL is returned??
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = lstlast_ps(*lst);
		current->next = new;
	}
}

t_stack	*lstnew_ps(long long int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	lstclear_ps(t_stack **lst)
{
	t_stack	*current;
	t_stack	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	stack_size(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
