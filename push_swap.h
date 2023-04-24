/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:31:31 by dmaessen          #+#    #+#             */
/*   Updated: 2023/04/21 13:41:07 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdio.h> 

typedef struct s_stack
{
	int				indexx;
	int				data;
	struct s_stack	*next;
}	t_stack;

int				main(int argc, char **argv);
void			fill_stack(char **str, t_stack **stacka);
void			assess_sort(t_stack **stacka);

t_stack			*lstnew_ps(long long int data);
t_stack			*lstlast_ps(t_stack *lst);
void			lstadd_back_ps(t_stack **lst, long long int res);
void			lstclear_ps(t_stack **lst);
int				stack_size(t_stack *lst);

void			free_str(char **str);
void			exit_error(int i);
void			free_stack(t_stack **stack);
void			free_str_error(char **str);
void			free_stack_error(t_stack **stack, int error);
long long int	atoi_long(const char *str);
int				isdouble(t_stack *stacka);
int				isordered(t_stack *stacka);

void			lstadd_front_ps(t_stack **lst, t_stack *new);
void			pb(t_stack **stacka, t_stack **stackb);
void			pa(t_stack **stacka, t_stack **stackb);
void			rra(t_stack **stacka);
void			rrb(t_stack **stackb);
void			ra(t_stack **stacka);
void			rb(t_stack **stackb);
void			rr(t_stack **stacka, t_stack **stackb);
void			sa(t_stack **stacka);
void			sb(t_stack **stackb);
void			ss(t_stack **stacka, t_stack **stackb);

void			little_two(t_stack **stacka);
void			little_three(t_stack **stacka);
void			little_four(t_stack **stacka, t_stack **stackb);
void			little_five(t_stack **stacka, t_stack **stackb);
void			find_smallest(t_stack **stacka);

void			big_sort(t_stack **stacka, t_stack **stackb);
int				buckets(t_stack *stacka);
int				search_top(t_stack *stacka, int x);
int				search_bottom(t_stack *stacka, int x);
void			move_to_b(t_stack **stacka, t_stack **stackb, int top, int b);
void			move_to_b2(t_stack **stacka, int top);
t_stack			*lst_position(t_stack *lst, int iter);
int				locate_biggest(t_stack *stackb);
void			push_back(t_stack **stacka, t_stack **stackb, int x);

void			index_init(t_stack *stacka);
void			index_stack(t_stack **stacka);
int				index_min(t_stack *stacka, int i);

#endif