/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:43:44 by edegraev          #+#    #+#             */
/*   Updated: 2024/03/03 10:55:06 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_target(t_stack *stack_b, t_node *c_a)
{
	t_node	*t_b;
	t_node	*c_b;

	t_b = get_maximal_number_node(stack_b);
	if (c_a->value > t_b->value)
	{
		c_a->rb = get_stack_position(stack_b, t_b->value);
		c_a->rrb = get_stack_size(stack_b) - c_a->rb;
		return (t_b);
	}
	if (c_a->value < get_minimal_number_node(stack_b)->value)
	{
		c_a->rb = get_stack_position(stack_b, t_b->value);
		c_a->rrb = get_stack_size(stack_b) - c_a->rb;
		return (t_b);
	}
	t_b = get_minimal_number_node(stack_b);
	c_b = stack_b->top;
	while (c_b != NULL)
	{
		if (c_b->value < c_a->value && (t_b == NULL || c_b->value > t_b->value))
			t_b = c_b;
		c_b = c_b->next;
	}
	return (t_b);
}

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*target;
	t_data	d;
	int		stack_pos_a;
	int		move;

	current_a = stack_a->top;
	while (current_a != NULL)
	{
		stack_pos_a = get_stack_position(stack_a, current_a->value);
		current_a->ra = stack_pos_a;
		current_a->rra = get_stack_size(stack_a) - stack_pos_a;
		target = get_target(stack_b, current_a);
		current_a->rb = get_stack_position(stack_b, target->value);
		current_a->rrb = get_stack_size(stack_b) - current_a->rb;
		move = 0;
		d.ra = current_a->ra;
		d.rb = current_a->rb;
		d.rra = current_a->rra;
		d.rrb = current_a->rrb;
		if (!algo_move_and_cost(&d, &move, &current_a->cost))
			quit("Error: in set cost 1\n", stack_a, stack_b);
		current_a = current_a->next;
	}
}

t_node	*find_low_cost(t_stack *stack_a)
{
	t_node	*current_a;
	t_node	*min_node;

	current_a = stack_a->top;
	min_node = current_a;
	while (current_a != NULL)
	{
		if (current_a->cost < min_node->cost)
			min_node = current_a;
		current_a = current_a->next;
	}
	return (min_node);
}

static void	algo_end(t_stack *stack_a, t_stack *stack_b)
{
	int	max;

	max = get_maximal_number(stack_b);
	if (get_stack_position(stack_b, max) > get_stack_size(stack_b) / 2)
	{
		while (stack_b->top->value != max)
			action_do("rrb", stack_a, stack_b);
	}
	else
	{
		while (stack_b->top->value != max)
			action_do("rb", stack_a, stack_b);
	}
	while (stack_b->top != NULL)
		action_do("pa", stack_a, stack_b);
}

void	algo(t_stack *stack_a, t_stack *stack_b)
{
	action_do("pb", stack_a, stack_b);
	action_do("pb", stack_a, stack_b);
	if (stack_b->top->next->value > stack_b->top->value)
		action_do("sb", stack_a, stack_b);
	action_do("pb", stack_a, stack_b);
	if (stack_b->top->next->next->value > stack_b->top->value)
		action_do("rb", stack_a, stack_b);
	else if (stack_b->top->next->value > stack_b->top->value)
		action_do("sb", stack_a, stack_b);
	while (stack_a->top != NULL)
	{
		set_cost(stack_a, stack_b);
		move_low_cost(stack_a, stack_b, find_low_cost(stack_a));
	}
	algo_end(stack_a, stack_b);
}
