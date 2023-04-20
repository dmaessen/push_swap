/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:31:20 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 11:45:29 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(t_stack *stacka)
{
    int value;
    int i;
    
    i = 0;
    while (stacka != NULL)
    {
        value = stacka->data;
        printf("[%d || indexx %d] data= %d\n", i, stacka->indexx, value);
        stacka = stacka->next;
        i++;
    }
}

void assess_sort(t_stack **stacka)
{
	int count;
    t_stack **stackb;
	
    stackb = (t_stack **)malloc(sizeof(t_stack)); // protect ??
    (*stackb) = NULL;
	count = stack_size(*stacka); // and if empty, is that possible??
	if (count == 2)
		little_two(stacka);
	if (count == 3)
		little_three(stacka);
    if (count == 4)
		little_four(stacka, stackb);
	if (count == 5)
		little_five(stacka, stackb);
	else
		big_sort(stacka, stackb);
    free_stack(stacka);
    free_stack(stackb);
}

int main(int argc, char **argv)
{
    t_stack **stacka;
    int i;
    int j;
    long long int res;
    char **str;

    if (argc <= 1)
        exit_error();
    if (argc == 2)
        str = ft_split(argv[1], ' '); // protect it
    else
        str = argv;
    stacka = (t_stack **)malloc(sizeof(t_stack)); // protect malloc??
    (*stacka) = NULL;
    i = 1;
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
        if (isdouble(str) == 0)
            free_str_error(str);
        res = atoi_long(str[i]);
		if (res > INT_MAX)
		    free_str_error(str);
        lstadd_back_ps(stacka, res);
        i++;
    }
    // free_str(str); // so this not needed?
    if (stack_size(*stacka) == 0 || isordered(*stacka) == 0)
    {
        lstclear_ps(stacka);
		return (0);  // or exit; nothing to be done/sorted so can stop already
	}
	assess_sort(stacka);
}

/*
APPROACH:
    - check the array if:
        1. valid (duplicates)
        2. already sorted (happens later)
        3. enough arg
    - implement error handling, print "Error" on STDERR if osmething happened (if alphabet in there, or duplicates...)
    - convert array to int (with atoi) to give them a sort of index
    - make a fucntion for small array 10/20max elements or something
    - make a function for bigger array 100/500 elements
    - make functions: push // swap // ...


    EDGECASES:
    --> if strsrch space then split on space
    --> if empty string as input do ...
    --> test on leaks
    --> 
    
    TO DO:
    - fix push_moves.c --> WORKS NOW
    - fix rotate_moves.c --> WORKS NOW
    - fix rev_rotate_moves.c --> WORKS NOW
    - test for 3 --> WORKS NOW FOR ALL COMBI
    - rewrite little_five/four --> WORKS NOW
    - make for big_sort // choose algo
    
*/