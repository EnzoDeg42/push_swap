/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:11:18 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/27 14:11:28 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_node	*current1;
	t_node	*current2;

	current1 = stack->top;
	while (current1 != NULL)
	{
		current2 = current1->next;
		while (current2 != NULL)
		{
			if (current1->value == current2->value)
				return (1);
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	return (0);
}

void	initialize_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack))
		quit("Error: Memory allocation failed\n", *stack, NULL);
	(*stack)->top = NULL;
}
