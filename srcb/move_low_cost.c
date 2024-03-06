/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_low_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:37:28 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/27 12:49:39 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_low_cost_b_1(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	while (node->ra > 0 && node->rb > 0)
	{
		action_do("rr", stack_a, stack_b);
		node->ra--;
		node->rb--;
	}
	move_low_cost_rb(stack_a, stack_b, node);
	move_low_cost_ra(stack_a, stack_b, node);
	action_do("pb", stack_a, stack_b);
}

static void	move_low_cost_b_2(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	while (node->rra > 0 && node->rrb > 0)
	{
		action_do("rrr", stack_a, stack_b);
		node->rra--;
		node->rrb--;
	}
	move_low_cost_rrb(stack_a, stack_b, node);
	move_low_cost_rra(stack_a, stack_b, node);
	action_do("pb", stack_a, stack_b);
}

static void	move_low_cost_b_3(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	move_low_cost_ra(stack_a, stack_b, node);
	move_low_cost_rrb(stack_a, stack_b, node);
	action_do("pb", stack_a, stack_b);
}

void	move_low_cost(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	int		best;
	t_data	d;

	d.ra = node->ra;
	d.rb = node->rb;
	d.rra = node->rra;
	d.rrb = node->rrb;
	algo_move_and_cost(&d, &best, &node->cost);
	if (best == 0)
		action_do("pb", stack_a, stack_b);
	else if (best == 1)
		move_low_cost_b_1(stack_a, stack_b, node);
	else if (best == 2)
		move_low_cost_b_2(stack_a, stack_b, node);
	else if (best == 3)
		move_low_cost_b_3(stack_a, stack_b, node);
	else if (best == 4)
	{
		move_low_cost_rb(stack_a, stack_b, node);
		move_low_cost_rra(stack_a, stack_b, node);
		action_do("pb", stack_a, stack_b);
	}
}
