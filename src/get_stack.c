/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:00:38 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/22 09:25:07 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_position(t_stack *stack, int value)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current != NULL)
	{
		if (current->value == value)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

int	get_stack_size(t_stack *stack)
{
	t_node	*current;
	int		size;

	current = stack->top;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
