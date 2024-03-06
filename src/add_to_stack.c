/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:03:24 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/27 13:40:14 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_top_stack(t_stack *stack, t_node *node)
{
	stack->top = node;
	if (stack->top == NULL)
		return (0);
	return (1);
}

int	add_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	if (stack->top == NULL)
	{
		if (!set_top_stack(stack, new_node))
			return (0);
	}
	else
	{
		current = stack->top;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (1);
}
