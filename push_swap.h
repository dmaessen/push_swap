/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:31:31 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/20 11:39:56 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <limits.h>

// to rm
# include <stdio.h> 

typedef struct s_stack
{
    int indexx;
	int data; // NO POINTER
	struct s_stack	*next;
}   t_stack;

/* main.c */
int 	main(int argc, char **argv);
void 	assess_sort(t_stack **stacka);

/* LIST RELATED: lists.c */
t_stack	*lstnew_ps(long long int data);
t_stack	*lstlast_ps(t_stack *lst);
//void	lstadd_back_ps(t_stack **lst, t_stack *new);
void	lstadd_back_ps(t_stack **lst, long long int res);
void	lstclear_ps(t_stack **lst);
int		stack_size(t_stack *lst);

/* ERRORS OR FREE RELATED: error_free.c */
void	free_str(char **str);
void 	exit_error();
void	free_stack(t_stack **stack);
void	free_str_error(char **str);

/* CHECKS: check.c */
long long int	atoi_long(const char *str);
int 	isdouble(char **str);
int 	isordered(t_stack *stacka);

/* ALL POSSIBLE MOVES: .._moves.c */
void	lstadd_front_ps(t_stack **lst, t_stack *new);
void 	pb(t_stack **stacka, t_stack **stackb);
void 	pa(t_stack **stacka, t_stack **stackb);
void	rra(t_stack **stacka);
void	rrb(t_stack **stackb);
void	rrr(t_stack **stacka, t_stack **stackb);
void 	ra(t_stack **stacka);
void 	rb(t_stack **stackb);
void 	rr(t_stack **stacka, t_stack **stackb);
void	sa(t_stack **stacka);
void	sb(t_stack **stackb);
void	ss(t_stack **stacka, t_stack **stackb);

/* SORT FOR SMALL INPUT: litte_sort.c */
void	little_two(t_stack **stacka);
void 	little_three(t_stack **stacka);
void 	little_four(t_stack **stacka, t_stack **stackb);
void 	little_five(t_stack **stacka, t_stack **stackb);

/* SORT FOR BIGGER INPUTS: big_sort.c */
void 	big_sort(t_stack **stacka, t_stack **stackb);
int 	buckets(t_stack *stacka); // using??
int 	scan_b100(t_stack *stackb);
int 	scan_b500(t_stack *stackb);
int 	search_top(t_stack *stacka, int x);
int 	search_bottom(t_stack *stacka, int x);
void 	move_to_b(t_stack **stacka, t_stack **stackb, int top, int bottom);
// void 	choice_ra_rra(t_stack **stacka, t_stack **stackb, int mode, int i);
t_stack	*lst_position(t_stack *lst, int iter); // put this in seperate ft
int	 	locate_biggest(t_stack *stackb); // using??

/* FOR INDEXING STACK: index.c */
void	index_init(t_stack *stacka);
void	index_stack(t_stack **stacka);
int 	index_min(t_stack *stacka, int i);

// TO REMOVE
void ft_print_stack(t_stack *stacka);

#endif