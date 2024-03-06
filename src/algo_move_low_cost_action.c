/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_low_cost_action.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:37:41 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/27 12:40:23 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_low_cost_rrb(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	while (node->rrb > 0)
	{
		action_do("rrb", stack_a, stack_b);
		node->rrb--;
	}
}

void	move_low_cost_ra(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	while (node->ra > 0)
	{
		action_do("ra", stack_a, stack_b);
		node->ra--;
	}
}

void	move_low_cost_rb(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	while (node->rb > 0)
	{
		action_do("rb", stack_a, stack_b);
		node->rb--;
	}
}

void	move_low_cost_rra(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	while (node->rra > 0)
	{
		action_do("rra", stack_a, stack_b);
		node->rra--;
	}
}
