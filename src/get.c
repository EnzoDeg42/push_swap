/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:31:44 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/27 11:48:06 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_minimal_number(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (stack->top == NULL)
		return (0);
	current = stack->top;
	min = current->value;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

t_node	*get_minimal_number_node(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	if (stack->top == NULL)
		return (NULL);
	current = stack->top;
	min = current;
	while (current != NULL)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

int	get_maximal_number(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (stack->top == NULL)
		return (0);
	current = stack->top;
	max = current->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

t_node	*get_maximal_number_node(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	if (stack->top == NULL)
		return (NULL);
	current = stack->top;
	max = current;
	while (current != NULL)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}
