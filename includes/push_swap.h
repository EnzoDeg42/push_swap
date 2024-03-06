/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:14:08 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/29 15:17:40 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				position;
	int				cost;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	struct s_node	*next;
}	t_node;

typedef struct s_data
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}	t_data;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

// action_both.c
void	action_swap_both(t_stack *stack_a, t_stack *stack_b);
void	action_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	action_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

// action_do.c
int		action_do(char *str, t_stack *stack_a, t_stack *stack_b);

// action.c
void	action_swap(t_stack *stack);
void	action_push(t_stack *stack_a, t_stack *stack_b);
void	action_rotate(t_stack *stack);
void	action_reverse_rotate(t_stack *stack);

// add_to_stack.c
int		add_to_stack(t_stack *stack, int value);

// algo_move_low_cost_action.c
int		algo_move_and_cost(t_data *d, int *move, int *cost);

// algo_move_low_cost_action.c
void	move_low_cost_rrb(t_stack *stack_a, t_stack *stack_b, t_node *node);
void	move_low_cost_ra(t_stack *stack_a, t_stack *stack_b, t_node *node);
void	move_low_cost_rb(t_stack *stack_a, t_stack *stack_b, t_node *node);
void	move_low_cost_rra(t_stack *stack_a, t_stack *stack_b, t_node *node);

// algo_short.c
int		short_algo(t_stack *stack_a, t_stack *stack_b);

// algo.c
void	algo(t_stack *stack_a, t_stack *stack_b);

// display.c
void	display_stack(t_stack *stack);
void	display_vertical_stacks(t_stack *stack_a, t_stack *stack_b);
void	display_stack_data(t_stack *stack);
void	display_stack_data_variation(t_stack *stack);

// ft_*.c
long	ft_atol(const char *str);
char	**ft_split(char const *s);
int		ft_strfind(const char *s1, const char c);
int		ft_strlen(const char *str);
int		ft_strlen_without_firsts_zeros(char *str);
void	ft_swap(int *a, int *b);

// get_stack.c
int		get_stack_position(t_stack *stack, int value);
int		get_stack_size(t_stack *stack);

// get_stack.c
int		get_stack_position(t_stack *stack, int value);
int		get_stack_size(t_stack *stack);

// get.c
int		get_minimal_number(t_stack *stack);
t_node	*get_minimal_number_node(t_stack *stack);
int		get_maximal_number(t_stack *stack);
t_node	*get_maximal_number_node(t_stack *stack);

// is_sorted.c
int		is_sorted(t_stack *stack);

// is_valid_number_format.c
int		is_valid_number_format(char *str);

// move_low_cost.c
void	move_low_cost(t_stack *stack_a, t_stack *stack_b, t_node *node);

// push_swap_extra.c
int		has_duplicates(t_stack *stack);
void	initialize_stack(t_stack **stack);

// quit.c
void	quit(char *msg, t_stack *stack_a, t_stack *stack_b);
void	ft_putstr(int exit, char *str);

#endif