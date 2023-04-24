/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:59:27 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/21 12:29:43 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	atoi_long(const char *str)
{
	int				i;
	int				sign;
	long long int	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (sign * nb);
}

int	isdouble(t_stack *stacka)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stacka;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->data == temp2->data)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	isordered(t_stack *stacka)
{
	t_stack	*next;

	next = stacka->next;
	while (next != NULL)
	{
		if (stacka->data < next->data)
		{
			stacka = stacka->next;
			next = next->next;
		}
		else
			return (1);
	}
	return (0);
}
