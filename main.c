/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:31:20 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/24 16:16:53 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ft_print_stack(t_stack *stacka)
// {
//     int value;
//     int i;
    
//     i = 0;
//     while (stacka != NULL)
//     {
//         value = stacka->data;
//         printf("[%d || indexx %d] data= %d\n", i, stacka->indexx, value);
//         stacka = stacka->next;
//         i++;
//     }
// }

void	assess_sort(t_stack **stacka)
{
	int		count;
	t_stack	**stackb;

	stackb = (t_stack **)malloc(sizeof(t_stack));
	if (stackb == NULL)
		exit(1);
	(*stackb) = NULL;
	count = stack_size(*stacka);
	if (count == 2)
		little_two(stacka);
	else if (count == 3)
		little_three(stacka);
	else if (count == 4)
		little_four(stacka, stackb);
	else if (count == 5)
		little_five(stacka, stackb);
	else
		big_sort(stacka, stackb);
	free_stack(stacka);
	free_stack(stackb);
}

void	fill_stack(char **str, t_stack **stacka)
{
	long long int	res;
	int				i;
	int				j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == '-')
				j++;
			if (ft_isdigit(str[i][j]) == 0)
				free_str_error(str);
			j++;
		}
		res = atoi_long(str[i]);
		if (res > INT_MAX || res < INT_MIN)
			free_str_error(str);
		lstadd_back_ps(stacka, res);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stacka;
	char	**str;
	int		i;

	if (argc <= 1)
		exit(1);
	stacka = (t_stack **)malloc(sizeof(t_stack));
	if (stacka == NULL)
		exit(1);
	(*stacka) = NULL;
	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str == NULL)
			exit (1);
		fill_stack(str, stacka);
		free_str(str);
		i++;
	}
	if (isdouble(*stacka) == 0)
		free_stack_error(stacka, 1);
	if (stack_size(*stacka) == 0 || isordered(*stacka) == 0)
		free_stack_error(stacka, 0);
	assess_sort(stacka);
}
